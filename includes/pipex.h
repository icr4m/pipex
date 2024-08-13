/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:06:42 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/13 04:23:56 by ijaber           ###   ########.fr       */
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

// check args
void	check_args(int ac, char **av, t_pipex pipex);

// errors
void	push_swap_error(char *error_message);

#endif