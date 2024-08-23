/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:30:16 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 22:15:44 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_movement(int keycode)
{
	return ((keycode == UP_KEY || keycode == LEFT_KEY)
		|| (keycode == DOWN_KEY || keycode == RIGHT_KEY));
}

bool	is_wall(char c)
{
	return (c == WALL);
}
