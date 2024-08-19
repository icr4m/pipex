/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 03:32:19 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 08:59:06 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_command(char **multiple_path, char *av, t_pipex *pipex)
{
	size_t	i;
	char	*command;
	char	*temp;

	i = INDEX_START;
	while (multiple_path[i])
	{
		temp = NULL;
		command = NULL;
		temp = ft_strjoin(multiple_path[i], "/");
		command = ft_strjoin(temp, av);
		free(temp);
		if (access(command, X_OK) != -1)
		{
			return (command);
		}
		free(command);
		i++;
	}
	pipex_error_free("Wrong command.", pipex);
	return (NULL);
}

void	parse_args(t_pipex *pipex)
{
	size_t	i;

	i = INDEX_START;
	pipex->cmd_full = (char **)malloc(pipex->cmd_count * sizeof(char *));
	while (i < pipex->cmd_count)
	{
		pipex->cmd_full[i] = find_command(pipex->cmd_paths,
				pipex->args_paths[i][0], pipex);
		ft_free_tab(pipex->args_paths[i]);
		i++;
	}
}
