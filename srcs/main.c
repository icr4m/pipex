/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:05:31 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/13 19:25:04 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int ac, char **av)
// {
// 	t_pipex	*pipex;

// 	check_args(ac, av, pipex);
// 	parse_cmds()
// }

int	main(int ac, char **av, char **envp)
{
	for (int i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
	return (0);
}
