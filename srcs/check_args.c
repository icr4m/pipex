/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:52:29 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/14 02:59:57 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av, t_pipex *pipex)
{
	if (ac < MIN_ARGC)
		pipex_error("Usage : ./pipex file1 cmd1 cmd2 file2");
	if (access(av[1], R_OK) == -1)
		pipex_error("Permission denined on file1");
	if (access(av[4], R_OK) == -1)
		pipex_error("Permission denined on file2");
}
