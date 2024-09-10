/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:53 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/10 15:34:54 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	check_args_bonus(ac, av, &pipex);
	init_pipex(&pipex, ac);
	parse_cmds(av + pipex.here_doc, envp, &pipex);
	parse_args(&pipex);
	exec_bonus(&pipex, av, ac);
	exit_and_free(&pipex);
}
