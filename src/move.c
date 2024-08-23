/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:02:28 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 23:58:13 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_player *player)
{
	if (player->target_world.x < player->world.x)
		player->world.x -= STEP_SIZE;
}

void	move_right(t_player *player)
{
	if (player->target_world.x > player->world.x)
		player->world.x += STEP_SIZE;
}

void	move_up(t_player *player)
{
	if (player->target_world.y < player->world.y)
		player->world.y -= STEP_SIZE;
}

void	move_down(t_player *player)
{
	if (player->target_world.y > player->world.y)
		player->world.y += STEP_SIZE;
}

void	move_player_step(t_player *player)
{
	if (player->state == MOVE_LEFT)
		move_left(player);
	if (player->state == MOVE_RIGHT)
		move_right(player);
	if (player->state == MOVE_DOWN)
		move_down(player);
	if (player->state == MOVE_UP)
		move_up(player);
	player->hitbox = set_hitbox(&player->world);
}
