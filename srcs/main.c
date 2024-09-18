/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:50:02 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/11 08:58:26 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	check_args_bonus(ac, av, &pipex);
	init_pipex(&pipex, ac);
	parse_cmds(av, envp, &pipex);
	parse_args(&pipex);
	exec(&pipex, av, ac);
	exit_and_free(&pipex);
}
