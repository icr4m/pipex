/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:22:07 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/20 17:22:42 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_bonus(int ac, char **av, t_pipex *pipex)
{
	if (ac < MIN_ARGC)
		pipex_error("Usage : ./pipex file1 cmd1 cmd2 ... file2");
	if (access(av[1], R_OK) == -1)
		pipex_error("Permission denined on file1");
}
