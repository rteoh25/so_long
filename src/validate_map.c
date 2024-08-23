/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:17:25 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 15:05:13 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_boundaries(char **layout, int map_height, int map_width)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map_width)
	{
		if (layout[y][x] != WALL)
			error_msg("MAP is not closed at the top");
		x++;
	}
	while (y < map_height - 1)
	{
		if (layout[y][0] != WALL || layout[y][map_width - 1] != WALL)
			error_msg("MAP is not closed at the side");
		y++;
	}
	x = 0;
	while (x < map_width)
	{
		if (layout[map_height - 1][x] != WALL)
			error_msg("MAP is not closed at the bottom");
		x++;
	}
}

void	validate_map(t_map *map, t_player *player)
{
	if (map->height == 0)
		msg("Map file is empty\n");
	if (map->player_count != 1)
		msg("Missing player, should have at least 1\n");
	if (map->collectible_count < 1)
		msg("Missing collectible, should have at least 1\n");
	if (map->exit_count != 1)
		msg("Map should have 1 exit\n");
	check_boundaries(map->layout, map->height, map->width);
	check_valid_path(map, &player->tile, map->layout);
}
