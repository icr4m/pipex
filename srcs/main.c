/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:05:31 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/14 00:41:31 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	init_pipex(&pipex);
	check_args(ac, av, &pipex);
	parse_cmds(av, envp, &pipex);
}
