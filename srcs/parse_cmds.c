/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:45:00 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 08:55:01 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char *name, char **envp)
{
	size_t	i;

	i = INDEX_START;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], name, 5) == 0)
			return (envp[i] + PATH_AMOUNT);
		i++;
	}
	return (NULL);
}

static void	get_command(char **av, char **envp, t_pipex *pipex)
{
	size_t	i;

	i = INDEX_START;
	pipex->args_paths = (char ***)malloc(pipex->cmd_count * sizeof(char **));
	if (!pipex->args_paths)
		pipex_error_free("malloc failed", pipex);
	while (i < pipex->cmd_count)
	{
		pipex->args_paths[i] = ft_split(av[i + 2], SPACE_CHAR);
		i++;
	}
}

void	parse_cmds(char **av, char **envp, t_pipex *pipex)
{
	pipex->cmd_paths = ft_split(get_path(PATH_STR, envp), TWO_DOTS);
	get_command(av, envp, pipex);
}
