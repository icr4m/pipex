/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:15:58 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/21 15:22:31 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_and_free(t_pipex *pipex)
{
	if (pipex->cmd_full != NULL)
		ft_free_tab(pipex->cmd_full);
	if (pipex->cmd_paths != NULL)
		ft_free_tab(pipex->cmd_paths);
	if (pipex->args_paths != NULL)
		ft_free_3d_tab(pipex->args_paths);
	exit(EXIT_SUCCESS);
}
