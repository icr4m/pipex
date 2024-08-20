/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:32:06 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/20 19:17:29 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_here_doc(t_pipex *pipex, char **av, int *pipe_fd)
{
	char	*read;

	close(pipe_fd[0]);
	while (1)
	{
		read = get_next_line(0);
		if (ft_strcmp(read, av[2]) == 0)
		{
			free(read);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(read, pipe_fd[1]);
		free(read);
	}
}

void	exec_here_doc(t_pipex *pipex, char **av)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		pipex_error_free("pipe error", pipex);
	pid = fork();
	if (pid == -1)
		pipex_error_free("fork error", pipex);
	else if (pid == 0)
		create_here_doc(pipex, av, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		wait(NULL);
	}
}

void	exec_bonus(t_pipex *pipex, char **av, int ac)
{
	int	index_ARGV;

	if (pipex->here_doc == 1)
	{
		index_ARGV = 3;
		pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (pipex->out_fd == -1)
			pipex_error_free("open failed", pipex);
		exec_here_doc(pipex, av);
	}
	else
	{
		index_ARGV = 2;
		pipex->in_fd = open(av[1], O_RDONLY);
		if (pipex->in_fd == -1)
			pipex_error_free("open failed", pipex);
		pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (pipex->out_fd == -1)
			pipex_error_free("open failed", pipex);
		dup2(pipex->in_fd, 0);
	}
	while (index_ARGV < ac - 2)
		do_pipe(av[index_ARGV++], pipex);
	dup2(pipex->out_fd, 1);
	exec(av[ac - 2], pipex);
}
