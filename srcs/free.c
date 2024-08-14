/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 02:04:46 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/14 02:05:30 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = INDEX_START;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
