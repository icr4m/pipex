/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:55:11 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/18 19:12:01 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_error(char *error_message)
{
	ft_printf("Error\n");
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	pipex_error_free(char *error_message, t_pipex *pipex)
{
	ft_printf("Error\n");
	perror(error_message);
	exit(EXIT_FAILURE);
}
