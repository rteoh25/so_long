/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:14:11 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 15:00:07 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
idea is to use bfs to find the exit
i want enqueue to do bfs, how ?
i want to add all the unvisited adjacent_tiles to the queue
check if the tiles im on is the exit or not / collectible
change the value of collectible or exit
*/

static void	enqueue(t_queue **queue, t_visited **visited,
						char **layout, t_position *tile)
{
	t_queue		*new_q_node;
	t_queue		**curr_ptr;
	const char	elem = layout[tile->y][tile->x];

	if (elem == WALL)
		return ;
	if (is_tile_visited(*visited, tile) || is_tile_queued(*queue, tile))
		return ;
	new_q_node = malloc(sizeof(t_queue));
	if (!new_q_node)
		error_msg(ERR_MALLOC);
	new_q_node->tile.x = tile->x;
	new_q_node->tile.y = tile->y;
	new_q_node->next = NULL;
	curr_ptr = queue;
	while (*curr_ptr != NULL)
		curr_ptr = &(*curr_ptr)->next;
	*curr_ptr = new_q_node;
}

static void	move_queued_tile(t_map *map, t_position *pos,
									int *coll_left, bool *exit_found)
{
	const int	x = (map->queue)->tile.x;
	const int	y = (map->queue)->tile.y;
	const char	tile = map->layout[y][x];

	pos->x = x;
	pos->y = y;
	if (tile == COLLECTIBLE)
		(*coll_left)--;
	else if (tile == EXIT)
		*exit_found = true;
	map->queue = update_queue(&map->queue);
	update_visited(map, pos);
}

static void	enqueue_adjacent_tiles(t_queue **queue, t_visited **visited, \
									char **layout, t_position *pos)
{
	const int	x = pos->x;
	const int	y = pos->y;

	enqueue(queue, visited, layout, &(t_position){x + 1, y});
	enqueue(queue, visited, layout, &(t_position){x - 1, y});
	enqueue(queue, visited, layout, &(t_position){x, y + 1});
	enqueue(queue, visited, layout, &(t_position){x, y - 1});
}

/*
enqueue first so the queue should have the tile of the player first
*/
void	check_valid_path(t_map *map, t_position *pos, char **layout)
{
	int			coll_left;
	bool		exit_found;
	t_position	tmp;

	tmp = (t_position){.x = pos->x, .y = pos->y};
	coll_left = map->collectible_count;
	exit_found = false;
	map->visited = NULL;
	map->queue = NULL;
	enqueue(&map->queue, &map->visited, layout, pos);
	while (map->queue != NULL)
	{
		move_queued_tile(map, &tmp, &coll_left, &exit_found);
		enqueue_adjacent_tiles(&map->queue, &map->visited, layout, &tmp);
	}
	free_visited(&map->visited);
	if (exit_found != true)
		msg("No paths lead to exit");
	if (coll_left != 0)
		msg("No paths lead to collectibles");
}
