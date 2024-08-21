/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:32:06 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/21 11:21:09 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_bonus(int index_cmd, t_pipex *pipex)
{
	pid_t	pid;
	int		pipe_fd[2];

	printf("test\n");
	if (pipe(pipe_fd) == -1)
		pipex_error_free("Pipe Failed", pipex);
	pid = fork();
	if (pid == -1)
		pipex_error_free("Fork Failed", pipex);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		execve(pipex->cmd_full[index_cmd], pipex->args_paths[index_cmd], NULL);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
	}
}

void	exec_bonus(t_pipex *pipex, char **av, int ac)
{
	int	index_ARGV;

	index_ARGV = INDEX_ARGV;
	if (pipex->here_doc == 1)
	{
		pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (pipex->out_fd == -1)
			pipex_error_free("open failed", pipex);
		exec_here_doc(pipex, av);
	}
	else
	{
		pipex->in_fd = open(av[1], O_RDONLY);
		if (pipex->in_fd == -1)
			pipex_error_free("open failed", pipex);
		pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (pipex->out_fd == -1)
			pipex_error_free("open failed", pipex);
		dup2(pipex->in_fd, 0);
	}
	while (index_ARGV++ < ac - 2 - pipex->here_doc)
		child_bonus(index_ARGV, pipex);
	dup2(pipex->out_fd, 1);
	execve(pipex->cmd_full[index_ARGV], pipex->args_paths[index_ARGV], NULL);
}
