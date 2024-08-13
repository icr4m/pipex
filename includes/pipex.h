/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:06:42 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/14 00:38:19 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft/includes/ft_printf.h"
# include "../Libft/libft/includes/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define INDEX_START 0
# define PATH_STR "PATH="
# define PATH_AMOUNT 5
# define SLASH_STR "/"
# define SPACE_CHAR ' '
# define TWO_DOTS ':'

// check args
void	check_args(int ac, char **av, t_pipex *pipex);

// errors
void	push_swap_error(char *error_message);

// init pipex
void	init_pipex(t_pipex *pipex);

// parse cmds
void	parse_cmds(char **av, char **envp, t_pipex *pipex);

#endif