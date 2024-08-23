/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:10:34 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 17:54:56 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_tile_visited(t_visited *visited, t_position *tile)
{
	t_visited	*tmp;

	tmp = visited;
	while (tmp != NULL)
	{
		if (tmp->tile.x == tile->x && tmp->tile.y == tile->y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_tile_queued(t_queue *queue, t_position *tile)
{
	t_queue	*tmp;

	tmp = queue;
	while (tmp != NULL)
	{
		if (tmp->tile.x == tile->x && tmp->tile.y == tile->y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	free_visited(t_visited **visited)
{
	t_visited	*tmp;

	if (visited == NULL)
		return ;
	while (*visited)
	{
		tmp = (*visited)->next;
		free(*visited);
		*visited = tmp;
	}
	*visited = NULL;
}

void	update_visited(t_map *map, t_position *pos)
{
	t_visited	*new_visit;
	t_visited	**curr_ptr;

	new_visit = malloc(sizeof(*new_visit));
	if (!new_visit)
		error_msg(ERR_MALLOC);
	new_visit->tile.x = pos->x;
	new_visit->tile.y = pos->y;
	new_visit->next = NULL;
	curr_ptr = &map->visited;
	while (*curr_ptr != NULL)
		curr_ptr = &(*curr_ptr)->next;
	*curr_ptr = new_visit;
}

t_queue	*update_queue(t_queue **queue)
{
	void	*first;

	if (queue == NULL || *queue == NULL)
		return (NULL);
	first = *queue;
	*queue = (*queue)->next;
	free(first);
	return (*queue);
}
