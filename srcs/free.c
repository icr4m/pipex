/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 02:04:46 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/13 15:57:43 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_cmd(char **tab, t_pipex *pipex)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = INDEX_START;
	while (i < pipex->cmd_count)
	{
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = INDEX_START;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_3d_tab(char ***tab)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		ft_free_tab(tab[i]);
		i++;
	}
	free(tab);
}

void	exit_and_free(t_pipex *pipex)
{
	if (pipex->cmd_full != NULL)
		ft_free_cmd(pipex->cmd_full, pipex);
	if (pipex->cmd_paths != NULL)
		ft_free_tab(pipex->cmd_paths);
	if (pipex->args_paths != NULL)
		ft_free_3d_tab(pipex->args_paths);
	exit(EXIT_SUCCESS);
}
