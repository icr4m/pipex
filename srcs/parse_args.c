/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 03:32:19 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/13 15:47:34 by ijaber           ###   ########.fr       */
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
		if (!temp)
			pipex_error_free(NULL, pipex);
		command = ft_strjoin(temp, av);
		if (!command)
			pipex_error_free(NULL, pipex);
		free(temp);
		if (access(command, X_OK) != -1)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	parse_args(t_pipex *pipex)
{
	size_t	i;

	i = INDEX_START;
	pipex->cmd_full = (char **)ft_calloc(pipex->cmd_count + 1, sizeof(char *));
	if (!pipex->cmd_full)
		pipex_error_free(NULL, pipex);
	while (i < pipex->cmd_count)
	{
		pipex->cmd_full[i] = find_command(pipex->cmd_paths,
				pipex->args_paths[i][0], pipex);
		i++;
	}
}
