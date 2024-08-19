/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:31:01 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 13:57:08 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_pipex *pipex, char **av, int *pipe_fd)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		pipex_error_free("open failed", pipex);
	dup2(fd, 0);
	close(fd);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	execve(pipex->cmd_full[0], pipex->args_paths[0], NULL);
}

static void	parent(t_pipex *pipex, char **av, int *pipe_fd)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		pipex_error_free("open failed", pipex);
	dup2(fd, 1);
	close(fd);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	execve(pipex->cmd_full[1], pipex->args_paths[1], NULL);
}

void	exec(t_pipex *pipex, char **av)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		pipex_error_free("pipe error", pipex);
	pid = fork();
	if (pid == -1)
		pipex_error_free("fork error", pipex);
	else if (pid == 0)
		child(pipex, av, pipe_fd);
	parent(pipex, av, pipe_fd);
}
