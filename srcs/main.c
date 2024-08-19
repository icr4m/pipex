/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:05:31 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 13:20:20 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_pipex(t_pipex *pipex)
{
	printf("cmd_count: %zu\n", pipex->cmd_count);
	printf("cmd_full:\n");
	for (size_t i = 0; pipex->cmd_full[i] != NULL; i++)
	{
		printf("  %s\n", pipex->cmd_full[i]);
	}
	printf("cmd_paths:\n");
	for (size_t i = 0; pipex->cmd_paths[i] != NULL; i++)
	{
		printf("  %s\n", pipex->cmd_paths[i]);
	}
	printf("args_paths:\n");
	for (size_t i = 0; pipex->args_paths[i] != NULL; i++)
	{
		printf("  Command %zu:\n", i);
		for (size_t j = 0; pipex->args_paths[i][j] != NULL; j++)
		{
			printf("    %s\n", pipex->args_paths[i][j]);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	init_pipex(&pipex, ac);
	check_args(ac, av, &pipex	);
	parse_cmds(av, envp, &pipex);
	parse_args(&pipex);
	exec(&pipex, av);
}
