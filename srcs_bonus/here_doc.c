/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:13:00 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/21 16:04:31 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_here_doc(t_pipex *pipex, char **av, int *pipe_fd)
{
	char	*read;

	while (1)
	{
		read = get_next_line(0);
		if (ft_strncmp(read, av[2], ft_strlen(av[2])) == 0)
		{
			free(read);
			close(pipe_fd[1]);
			close(pipex->out_fd);
			exit_and_free(pipex);
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
