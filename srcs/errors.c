/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:55:11 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/13 15:57:59 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_error(char *error_message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}

void	pipex_error_free(char *error_msg, t_pipex *pipex)
{
	perror("Error");
	if (error_msg != NULL)
		ft_printf("%s\n", error_msg);
	if (pipex->cmd_full != NULL)
		ft_free_cmd(pipex->cmd_full, pipex);
	if (pipex->cmd_paths != NULL)
		ft_free_tab(pipex->cmd_paths);
	if (pipex->args_paths != NULL)
		ft_free_3d_tab(pipex->args_paths);
	exit(EXIT_FAILURE);
}
