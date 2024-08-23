/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:04:16 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 18:33:18 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_move_state(int keycode, t_player *player)
{
	if (keycode == UP_KEY)
		player->state = MOVE_UP;
	if (keycode == DOWN_KEY)
		player->state = MOVE_DOWN;
	if (keycode == LEFT_KEY)
		player->state = MOVE_LEFT;
	if (keycode == RIGHT_KEY)
		player->state = MOVE_RIGHT;
}

int	check_player_move_valid(int keycode, t_player *player, t_map *map)
{
	t_position	*tile;

	tile = &player->tile;
	if (keycode == UP_KEY)
		return (is_wall(map->layout[tile->y - 1][tile->x]));
	if (keycode == DOWN_KEY)
		return (is_wall(map->layout[tile->y + 1][tile->x]));
	if (keycode == LEFT_KEY)
		return (is_wall(map->layout[tile->y][tile->x - 1]));
	if (keycode == RIGHT_KEY)
		return (is_wall(map->layout[tile->y][tile->x + 1]));
	return (1);
}

t_position	set_delta(int keycode)
{
	t_position	delta;

	delta = (t_position){0};
	if (keycode == UP_KEY)
		delta.y -= 1;
	if (keycode == DOWN_KEY)
		delta.y += 1;
	if (keycode == LEFT_KEY)
		delta.x -= 1;
	if (keycode == RIGHT_KEY)
		delta.x += 1;
	return (delta);
}

void	set_player_state_idle(t_player *player, int keycode)
{
	if (keycode == LEFT_KEY)
		player->state = IDLE_LEFT;
	else if (keycode == UP_KEY)
		player->state = IDLE_RIGHT;
	else if (keycode == DOWN_KEY)
		player->state = IDLE_LEFT;
	else if (keycode == RIGHT_KEY)
		player->state = IDLE_RIGHT;
}

int	move_player(int keycode, t_game *game)
{
	t_player		*player;
	t_position		delta;

	player = game->entity.player;
	if (is_movement(keycode) && player->is_moving == false)
	{
		if ((check_player_move_valid(keycode, player, &game->map) == 1))
			set_player_state_idle(player, keycode);
		else
		{
			set_player_move_state(keycode, player);
			delta = set_delta(keycode);
			player->target_world.x += (delta.x * TILE_WIDTH);
			player->target_world.y += (delta.y * TILE_HEIGHT);
			player->is_moving = true;
			player->move_count++;
		}
	}
	if (keycode == ESC_KEY)
	{
		ft_putstr_fd("GAME EXITED\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
