/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:04:07 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 20:48:41 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pos(t_position *tile, t_position *world, t_position *pos)
{
	tile->x = pos->x;
	tile->y = pos->y;
	world->x = tile->x * TILE_WIDTH;
	world->y = tile->y * TILE_HEIGHT;
}

void	init_player(t_position *tile,
t_entity *entities, t_map *map, t_images *imgs)
{
	t_player	*player;

	if (++map->player_count > 1)
		msg("NO_HOMO");
	player = malloc(sizeof(*player));
	if (!player)
		error_msg(ERR_MALLOC);
	entities->player = player;
	set_pos(&player->tile, &player->world, tile);
	player->target_world.x = player->world.x;
	player->target_world.y = player->world.y;
	player->move_count = 0;
	set_player_animation(player, imgs);
	player->hitbox = set_hitbox(&player->world);
	player->state = IDLE_RIGHT;
	player->ticks = 0;
}

void	init_exit(t_position *tile, t_entity *entities, t_map *map)
{
	t_exit	*exit;

	if (++map->exit_count > 1)
		msg("more than one exit\n");
	exit = malloc(sizeof(*exit));
	if (!exit)
		error_msg(ERR_MALLOC);
	set_pos(&exit->tile, &exit->world, tile);
	exit->hitbox = set_hitbox(&exit->world);
	exit->is_unlocked = false;
	entities->exit = exit;
}
