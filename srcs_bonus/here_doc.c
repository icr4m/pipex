/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:13:00 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/21 07:13:56 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_here_doc(t_pipex *pipex, char **av, int *pipe_fd)
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
