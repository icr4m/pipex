/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:32:06 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/02 11:16:04 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_bonus(int index_cmd, t_pipex *pipex)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		pipex_error_free("Pipe Failed", pipex);
	pid = fork();
	if (pid == -1)
		pipex_error_free("Fork Failed", pipex);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		if (pipex->here_doc == 0)
			close(pipex->in_fd);
		close(pipex->out_fd);
		execve(pipex->cmd_full[index_cmd], pipex->args_paths[index_cmd], NULL);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		waitpid(pid, NULL, 0);
	}
}

static void	exec_bonus_final(t_pipex *pipex, int index_argv, int ac)
{
	if (pipex->here_doc == 0)
		close(pipex->in_fd);
	dup2(pipex->out_fd, STDOUT_FILENO);
	close(pipex->out_fd);
	execve(pipex->cmd_full[index_argv], pipex->args_paths[index_argv], NULL);
}

void	exec_bonus(t_pipex *pipex, char **av, int ac)
{
	int	index_argv;

	index_argv = INDEX_START;
	if (pipex->here_doc == 1)
	{
		pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
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
		dup2(pipex->in_fd, STDIN_FILENO);
	}
	while (index_argv < ac - 4 - pipex->here_doc)
		child_bonus(index_argv++, pipex);
	if (pipex->here_doc == 0)
		close(pipex->in_fd);
	exec_bonus_final(pipex, index_argv, ac);
}
