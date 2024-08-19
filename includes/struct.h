/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:16:49 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 07:29:22 by ijaber           ###   ########.fr       */
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
	size_t	cmd_count;
	char **cmd_full;    // les bin/user/cat
	char **cmd_paths;   // les /bin/user
	char ***args_paths; // les "cat -e" "wc -l"
}			t_pipex;

#endif