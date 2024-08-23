/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:35:12 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 19:07:28 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_map_elem(char c)
{
	return (c == WALL || c == FLOOR
		|| c == COLLECTIBLE
		|| c == PLAYER
		|| c == ENEMY
		|| c == EXIT);
}

void	init_walls(t_position *tile, t_entity	*entities)
{
	t_wall	*new_wall;
	t_wall	**curr_ptr;

	new_wall = malloc(sizeof(*new_wall));
	if (!new_wall)
		error_msg(ERR_MALLOC);
	new_wall->tile.x = tile->x;
	new_wall->tile.y = tile->y;
	new_wall->world.x = tile->x * TILE_WIDTH;
	new_wall->world.y = tile->y * TILE_HEIGHT;
	new_wall->next = NULL;
	curr_ptr = &entities->walls; 
	while (*curr_ptr != NULL)
		curr_ptr = &(*curr_ptr)->next;
	*curr_ptr = new_wall;
}

void	init_floors(t_position *tile, t_entity	*entities)
{
	t_floor	*new_floor;
	t_floor	**curr_ptr;

	new_floor = malloc(sizeof(*new_floor));
	if (!new_floor)
		error_msg(ERR_MALLOC);
	new_floor->tile.x = tile->x;
	new_floor->tile.y = tile->y;
	new_floor->world.x = tile->x * TILE_WIDTH;
	new_floor->world.y = tile->y * TILE_HEIGHT;
	new_floor->next = NULL;
	curr_ptr = &entities->floor;
	while (*curr_ptr != NULL)
		curr_ptr = &(*curr_ptr)->next;
	*curr_ptr = new_floor;
}

void	init_collectibles(t_position *tile,
t_entity *entities, t_map *map)
{
	static t_collectible	*tail = NULL;
	t_collectible			*new_col;

	new_col = malloc(sizeof(*new_col));
	if (!new_col)
		error_msg(ERR_MALLOC);
	new_col->tile.x = tile->x;
	new_col->tile.y = tile->y;
	new_col->world.x = tile->x * TILE_WIDTH;
	new_col->world.y = tile->y * TILE_HEIGHT;
	new_col->hitbox = set_hitbox(&new_col->world);
	new_col->next = NULL;
	if (entities->collectible == NULL)
	{
		entities->collectible = new_col;
		new_col->prev = NULL;
	}
	else
	{
		tail->next = new_col;
		new_col->prev = tail;
	}
	tail = new_col;
	map->collectible_count++;
}

void	init_game_entities(char *row,
t_entity *entities, t_map *map, t_images *imgs)
{
	static t_position	tile = {.x = 0, .y = 0};

	tile.x = 0;
	while (*row)
	{
		if (!valid_map_elem(*row))
			error_msg("Invalid character in map\n");
		if (*row == WALL)
			init_walls(&tile, entities);
		else
			init_floors(&tile, entities);
		if (*row == COLLECTIBLE)
			init_collectibles(&tile, entities, map);
		else if (*row == PLAYER)
			init_player(&tile, entities, map, imgs);
		else if (*row == EXIT)
			init_exit(&tile, entities, map);
		row++;
		tile.x++;
	}
	tile.y++;
}
