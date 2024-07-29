/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:37:13 by ijaber            #+#    #+#             */
/*   Updated: 2024/07/29 12:39:06 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**init_pipex(t_pipex pipex, char **av, int ac)
{
	pipex.in_fd = open(av[1], O_WRONLY | O_CREAT);
	pipex.out_fd = open(av[4], O_WRONLY | O_CREAT);
	pipex.cmd_count = ac - 2;
}
