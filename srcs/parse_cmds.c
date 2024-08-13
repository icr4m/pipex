/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:45:00 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/14 00:26:49 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_command(char **multiple_path, char *av)
{
	int		i;
	char	*command;

	i = 0;
	while (multiple_path[i])
	{
		command = ft_strjoin(multiple_path[i], "/");
		free(multiple_path[i]);
		command = ft_strjoin(command, av);
		if (access(command, X_OK) != -1)
		{
			ft_printf("command: %s\n", command);
			return (command);
		}
		free(command);
		i++;
	}
	return (NULL);
}

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

void	parse_cmds(char **av, char **envp, t_pipex *pipex)
{
	pipex->av2 = ft_split(av[2], SPACE_CHAR);
	pipex->av3 = ft_split(av[3], SPACE_CHAR);
	pipex->cmd_paths = ft_split(get_path(PATH_STR, envp), TWO_DOTS);
	find_command(pipex->cmd_paths, pipex->av2[0]);
	
	find_command(pipex->cmd_paths, pipex->av3[0]);
}
