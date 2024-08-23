/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:55:55 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 14:58:00 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	msg(char *err)
{
	write(1, "ERROR\n", 6);
	ft_putstr_fd(err, 1);
	exit(EXIT_SUCCESS);
}

void	error_msg(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
