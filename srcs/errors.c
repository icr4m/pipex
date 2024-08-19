/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:55:11 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 17:07:43 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_error(char *error_message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}

void	pipex_error_free(char *error_message, t_pipex *pipex)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_message);
	if (pipex->cmd_full != NULL)
		ft_free_tab(pipex->cmd_full);
	if (pipex->cmd_paths != NULL)
		ft_free_tab(pipex->cmd_paths);
	if (pipex->args_paths != NULL)
		ft_free_2d_tab(pipex->args_paths);
	exit(EXIT_FAILURE);
}
