/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:13:00 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/13 16:31:40 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_here_doc(t_pipex *pipex, char **av, int *pipe_fd)
{
	char	*read;

	ft_putstr_fd("pipe heredoc> ", 1);
	while (1)
	{
		read = get_next_line(0);
		if (ft_strncmp(read, av[2], ft_strlen(av[2])) == 0 && ft_strlen(read)
			- 1 == ft_strlen(av[2]))
		{
			free(read);
			close(pipe_fd[1]);
			exit_and_free(pipex);
		}
		ft_putstr_fd("pipe heredoc> ", 1);
		ft_putstr_fd(read, pipe_fd[1]);
		free(read);
	}
}

void	handle_here_doc(t_pipex *pipex, char **av)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		pipex_error_free("Pipe/Fork failed", pipex);
	pid = fork();
	if (pid == -1)
		pipex_error_free("Pipe/Fork failed", pipex);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		create_here_doc(pipex, av, pipe_fd);
		close(pipe_fd[1]);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		wait(NULL);
	}
}

void	handle_heredoc_pipes(int ac, char **av, char **envp, t_pipex *pipex)
{
	int	index_argv;

	index_argv = INDEX_START;
	parse_cmds(av + pipex->here_doc, envp, pipex);
	parse_args(pipex);
	pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (pipex->out_fd == -1)
		pipex_error_free(NULL, pipex);
	while (index_argv < ac - 4 - pipex->here_doc)
		child_multiple(index_argv++, pipex);
	dup2(pipex->out_fd, STDOUT_FILENO);
	close(pipex->out_fd);
	last_child_process(pipex, index_argv);
	while (waitpid(-1, NULL, 0) > 0)
		;
}
