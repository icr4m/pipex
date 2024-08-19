/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:06:42 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/19 13:50:33 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft/includes/ft_printf.h"
# include "../Libft/libft/includes/libft.h"
# include "struct.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define INDEX_START 0
# define INDEX_ARGV 1
# define MIN_ARGC 5
# define PATH_STR "PATH="
# define PATH_AMOUNT 5
# define SLASH_STR "/"
# define SPACE_CHAR ' '
# define TWO_DOTS ':'

// check args
void	check_args(int ac, char **av, t_pipex *pipex);

// errors
void	pipex_error(char *error_message);
void	pipex_error_free(char *error_message, t_pipex *pipex);

// exec
void	exec(t_pipex *pipex, char **av);

// free
void	ft_free_tab(char **tab);

// init pipex
void	init_pipex(t_pipex *pipex, int ac);

// parse args
void	parse_args(t_pipex *pipex);

// parse cmds
void	parse_cmds(char **av, char **envp, t_pipex *pipex);

#endif