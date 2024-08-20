/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:53 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/20 18:04:00 by ijaber           ###   ########.fr       */
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
}
