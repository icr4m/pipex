/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:53 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/21 10:36:26 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	print_pipex(t_pipex *pipex)
// {
// 	printf("cmd_count: %zu\n", pipex->cmd_count);
// 	printf("cmd_full:\n");
// 	for (size_t i = 0; pipex->cmd_full[i] != NULL; i++)
// 	{
// 		printf("  %s\n", pipex->cmd_full[i]);
// 	}
// 	printf("cmd_paths:\n");
// 	for (size_t i = 0; pipex->cmd_paths[i] != NULL; i++)
// 	{
// 		printf("  %s\n", pipex->cmd_paths[i]);
// 	}
// 	printf("args_paths:\n");
// 	for (size_t i = 0; pipex->args_paths[i] != NULL; i++)
// 	{
// 		printf("  Command %zu:\n", i);
// 		for (size_t j = 0; pipex->args_paths[i][j] != NULL; j++)
// 		{
// 			printf("    %s\n", pipex->args_paths[i][j]);
// 		}
// 	}
// }

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	check_args_bonus(ac, av, &pipex);
	init_pipex(&pipex, ac);
	parse_cmds(av, envp, &pipex);
	parse_args(&pipex);
	exec_bonus(&pipex, av, ac);
}
