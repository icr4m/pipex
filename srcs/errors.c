/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaber <ijaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:55:11 by ijaber            #+#    #+#             */
/*   Updated: 2024/08/13 04:00:05 by ijaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	push_swap_error(char *error_message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
