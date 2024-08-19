/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:16:49 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 16:48:49 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "pipex.h"

typedef struct s_pipex
{
	int		here_doc;
	int		is_invalid_infile;
	size_t	cmd_count;
	char	**cmd_full;
	char	**cmd_paths;
	char	***args_paths;
}			t_pipex;

#endif