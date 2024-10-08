/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multiple_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:32:06 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/13 16:31:36 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_multiple(int index_cmd, t_pipex *pipex)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		pipex_error_free("fork/pipe failed", pipex);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		if (pipex->here_doc == 0)
			close(pipex->in_fd);
		close(pipex->out_fd);
		if (pipex->cmd_full[index_cmd] == NULL)
			pipex_error_free("Command not found", pipex);
		execve(pipex->cmd_full[index_cmd], pipex->args_paths[index_cmd], NULL);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
}

void	last_child_process(t_pipex *pipex, int index_argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		pipex_error_free(NULL, pipex);
	else if (pid == 0)
	{
		if (pipex->cmd_full[index_argv] == NULL)
			pipex_error_free("Command not found", pipex);
		execve(pipex->cmd_full[index_argv], pipex->args_paths[index_argv],
			NULL);
	}
}

void	exec(t_pipex *pipex, char **av, int ac)
{
	int	index_argv;

	index_argv = INDEX_START;
	pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->out_fd == -1)
		pipex_error_free(NULL, pipex);
	pipex->in_fd = open(av[1], O_RDONLY);
	if (pipex->in_fd == -1)
		pipex_error_free(NULL, pipex);
	dup2(pipex->in_fd, STDIN_FILENO);
	while (index_argv < ac - 4)
		child_multiple(index_argv++, pipex);
	if (pipex->here_doc == 0)
		close(pipex->in_fd);
	dup2(pipex->out_fd, STDOUT_FILENO);
	close(pipex->out_fd);
	last_child_process(pipex, index_argv);
	while (waitpid(-1, NULL, 0) > 0)
		;
}
