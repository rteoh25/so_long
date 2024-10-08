/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:57:42 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 20:42:01 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define HITBOX_WIDTH 16
#define HITBOX_HEIGHT 16

t_hitbox	set_hitbox(t_position	*world)
{
	t_hitbox	hitbox;

	hitbox.top_left.x = world->x + (TILE_WIDTH - HITBOX_WIDTH) / 2;
	hitbox.top_left.y = world->y + (TILE_HEIGHT - HITBOX_HEIGHT) / 2;
	hitbox.bot_right.x = hitbox.top_left.x + HITBOX_WIDTH;
	hitbox.bot_right.y = hitbox.top_left.y + HITBOX_HEIGHT;
	return (hitbox);
}

bool	entities_collide(t_hitbox *entity1, t_hitbox *entity2)
{
	return ((entity1->top_left.x <= entity2->top_left.x
			&& entity1->bot_right.x >= entity2->top_left.x)
		&& (entity1->top_left.y <= entity2->top_left.y
			&& entity1->bot_right.y >= entity2->top_left.y));
}
