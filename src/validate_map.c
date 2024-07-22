/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:17:25 by rteoh             #+#    #+#             */
/*   Updated: 2024/07/22 13:33:04 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(s_map *map, t_player *player)
{
	if (map->height == 0)
		msg("Map file is empty\n");
	if (map->player_count == 0)
		msg("Missing player, should have at least 1\n");
	if (map->collectible_count < 1)
		msg("Map should have 1 collectible\n");
	if (map->exit_count != 1)
		msg("Map should have 1 exit\n");
	check_boundaries(map->layout)
}