/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:30:48 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/20 17:34:50 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, int ac)
{
	pipex->cmd_count = (size_t)ac - 3;
	pipex->cmd_full = NULL;
	pipex->cmd_paths = NULL;
	pipex->args_paths = NULL;
}
