/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:53 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/11 09:30:33 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	check_args_bonus(ac, av, &pipex);
	init_pipex(&pipex, ac);
	if (pipex.here_doc == 1)
	{
		handle_here_doc(&pipex, av);
		handle_heredoc_pipes(ac, av, envp, &pipex);
	}
	else
	{
		parse_cmds(av, envp, &pipex);
		parse_args(&pipex);
		exec(&pipex, av, ac);
	}
	exit_and_free(&pipex);
}
