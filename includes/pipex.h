/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:06:42 by ijaber            #+#    #+#             */
/*   Updated: 2024/09/13 15:57:51 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft/includes/ft_printf.h"
# include "../Libft/libft/includes/get_next_line_bonus.h"
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
# define MIN_ARGC_B 6
# define PATH_STR "PATH="
# define PATH_AMOUNT 5
# define SLASH_STR "/"
# define SPACE_CHAR ' '
# define TWO_DOTS ':'
# define HERE_DOC_STR "here_doc"

// check args bonus
void	check_args_bonus(int ac, char **av, t_pipex *pipex);

// errors
void	pipex_error(char *error_message);
void	pipex_error_free(char *error_msg, t_pipex *pipex);

// exec bonus
void	child_multiple(int index_cmd, t_pipex *pipex);
void	last_child_process(t_pipex *pipex, int index_argv);
void	exec(t_pipex *pipex, char **av, int ac);

// free
void	ft_free_cmd(char **tab, t_pipex *pipex);
void	exit_and_free(t_pipex *pipex);
void	ft_free_3d_tab(char ***tab);
void	ft_free_tab(char **tab);

// heredocc
void	handle_heredoc_pipes(int ac, char **av, char **envp, t_pipex *pipex);
void	handle_here_doc(t_pipex *pipex, char **av);

// init pipex
void	init_pipex(t_pipex *pipex, int ac);

// parse args
void	parse_args(t_pipex *pipex);

// parse cmd
void	parse_cmds(char **av, char **envp, t_pipex *pipex);

#endif