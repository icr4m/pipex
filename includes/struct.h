/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:16:49 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/14 00:15:09 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "pipex.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	// int		here_doc;
	int		is_invalid_infile;
	char	**cmd_paths;
	char	**av2;
	char	**av3;
}			t_pipex;

#endif