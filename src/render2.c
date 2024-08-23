/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:07:05 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 20:47:18 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_game *game, t_background *bg, t_images *imgs)
{
	while (bg != NULL)
	{
		put_image(game, imgs->background, bg->screen.x, bg->screen.y);
		bg = bg->next;
	}
}

void	render_walls(t_game *game, t_wall *wall, t_images *imgs)
{
	while (wall != NULL)
	{
		wall->screen.x = wall->world.x + game->offset.x;
		wall->screen.y = wall->world.y + game->offset.y;
		put_image(game, imgs->walls, wall->screen.x, wall->screen.y);
		wall = wall->next;
	}
}

void	render_floor(t_game *game, t_floor *floor, t_images *imgs)
{
	while (floor != NULL)
	{
		floor->screen.x = floor->world.x + game->offset.x;
		floor->screen.y = floor->world.y + game->offset.y;
		put_image(game, imgs->floor, floor->screen.x, floor->screen.y);
		floor = floor->next;
	}
}

void	render_collectible(t_game *game, t_collectible *collectible,
								t_images *imgs)
{
	put_image(game, imgs->collectible, -20, -30);
	while (collectible != NULL)
	{
		collectible->screen.x = collectible->world.x + game->offset.x;
		collectible->screen.y = collectible->world.y + game->offset.y;
		put_image(game, imgs->collectible,
			collectible->screen.x, collectible->screen.y);
		collectible = collectible->next;
	}
}

void	render_exit(t_game *game, t_exit *exit, t_images *imgs)
{
	exit->screen.x = exit->world.x + game->offset.x;
	exit->screen.y = exit->world.y + game->offset.y;
	if (exit->is_unlocked == true)
		put_image(game, imgs->exit_unlocked, exit->screen.x, exit->screen.y);
	else
		put_image(game, imgs->exit, exit->screen.x, exit->screen.y);
}
