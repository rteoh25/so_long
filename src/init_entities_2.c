/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:04:07 by rteoh             #+#    #+#             */
/*   Updated: 2024/07/22 13:14:20 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_postion(t_position *tile, t_position *world, t_position *pos)
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
		msg_error(ERR_MALLOC);
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

void	init_enemy(t_position *tile, t_entity *entities, t_images *imgs)
{
	t_enemy *new_enemy;
	if (!new_enemy)
		error_msg(ERR_MALLOC);
	set_positin(&new_enemy->tile, &new_enemy->world, tile);
	new_enemy->target_world.x = new_enemy->world.x;
	new_enemy->target_world.y = new_enemy->world.y;
	new_enemy->is_moving = false;
	new_enemy->ticks = 0;
	new_enemy->state = IDLE_LEFT;
	new_enemy->hitbox = set_hitbox(&new_enemy->world);
	set_enemy_animation(new_enemy, imgs);
	new_enemy->next = NULL;
	ft_lsdtadd_back(entities->enemy, new_enemy);
}

void	init_exit(t_position *tile, t_entity *entities, t_map *map)
{
	t_exit	*exit;

	if (++map->exit_count > 1)
		msg("more than one exit\n");
	exit = malloc(sizeof(*exit));
	if (!exit)
		error_msg(ERR_MALLOC);
	set_position(&exit->tile, &exit->world, tile);
	exit->hitbox = set_hitbox(&exit->world);
	exit->unlocked = false;
	entities->exit = exit;
}