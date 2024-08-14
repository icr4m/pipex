/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:45:00 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/14 02:55:08 by ijaber           ###   ########.fr       */
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
		temp = ft_strjoin(multiple_path[i], "/");
		command = ft_strjoin(temp, av);
		free(temp);
		if (access(command, X_OK) != -1)
			return (command);
		free(command);
		i++;
	}
	pipex_error_free("Wrong command.", pipex);
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

static void	get_command(char **av, char **envp, t_pipex *pipex)
{
	size_t	i;

	i = INDEX_START;
	while (av[i + INDEX_ARGV] )
	{
		
	}
}

void	parse_cmds(char **av, char **envp, t_pipex *pipex)
{
	pipex->av2 = ft_split(av[2], SPACE_CHAR);
	pipex->av3 = ft_split(av[3], SPACE_CHAR);
	pipex->cmd_paths = ft_split(get_path(PATH_STR, envp), TWO_DOTS);
	pipex->cmd_2 = find_command(pipex->cmd_paths, pipex->av2[0], pipex);
	pipex->cmd_3 = find_command(pipex->cmd_paths, pipex->av3[0], pipex);
	ft_free_tab(pipex->av2);
	ft_free_tab(pipex->av3);
	ft_free_tab(pipex->cmd_paths);
}
