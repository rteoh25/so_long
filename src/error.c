/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:55:55 by rteoh             #+#    #+#             */
/*   Updated: 2024/07/22 02:43:55 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		msg(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

void	error_msg(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}