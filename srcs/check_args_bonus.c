/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:22:07 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/13 16:32:11 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args_bonus(int ac, char **av, t_pipex *pipex)
{
	if (ac < MIN_ARGC)
		pipex_error("Usage : ./pipex_bonus file1 cmd1 ... cmd2 file2");
	if (ft_strcmp(av[1], HERE_DOC_STR) == 0)
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
	if (pipex->here_doc == 1 && ac < MIN_ARGC_B)
		pipex_error("Usage : ./pipex_bonus here_doc LIMITER cmd1 ... \
cmd2 file2");
}
