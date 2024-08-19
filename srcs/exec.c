/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:31:01 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 07:03:12 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(void)
{
	int	fd;
	fd = open_file()
}

void	parent(void)
{
}

void	exec(t_pipex *pipex)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		pipex_error("pipe error");
	pid = fork();
	if (pid == -1)
		pipex_error("fork error");
	else if (pid == 0)
		child
}
