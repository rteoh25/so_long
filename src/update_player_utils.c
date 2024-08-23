/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:05:09 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 20:41:53 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_idle(t_player *player)
{
	if (player->state == MOVE_LEFT)
		player->state = IDLE_LEFT;
	if (player->state == MOVE_RIGHT)
		player->state = IDLE_RIGHT;
	if (player->state == MOVE_DOWN)
		player->state = IDLE_LEFT;
	if (player->state == MOVE_UP)
		player->state = IDLE_RIGHT;
	player->animations[player->state]->frame_index = 0;
}

void	update_player_pos(t_player *player)
{
	if (player->state == MOVE_UP)
		player->tile.y -= 1;
	if (player->state == MOVE_DOWN)
		player->tile.y += 1;
	if (player->state == MOVE_RIGHT)
		player->tile.x += 1;
	if (player->state == MOVE_LEFT)
		player->tile.x -= 1;
}
