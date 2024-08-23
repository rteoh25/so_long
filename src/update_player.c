/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:51:42 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 14:47:16 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	player_collectible_collide(t_entity *entities, t_player *player,
									t_collectible *coll)
{
	while (coll != NULL)
	{
		if (entities_collide(&player->hitbox, &coll->hitbox))
		{
			if (coll->prev)
				coll->prev->next = coll->next;
			else
				entities->collectible = coll->next;
			if (coll->next)
				coll->next->prev = coll->prev;
			free(coll);
			return (true);
		}
		coll = coll->next;
	}
	return (false);
}

void	check_player_collision(t_game *game, t_entity *entities, t_map *map)
{
	t_exit *const			door = entities->exit;
	t_player *const			player = entities->player;
	t_collectible *const	coll = entities->collectible;

	if (player_collectible_collide(entities, player, coll))
	{
		if (--map->collectible_count == 0)
			entities->exit->is_unlocked = true;
	}
	if (entities->exit->is_unlocked
		&& entities_collide(&player->hitbox, &door->hitbox))
		exit_game(game);
}

void	update_player(t_game *game, t_player *player)
{
	check_player_collision(game, &game->entity, &game->map);
	player->current_animation = player->animations[player->state];
	if (player->is_moving)
	{
		move_player_step(player);
		game->offset.x = player->screen.x - player->world.x;
		game->offset.y = player->screen.y - player->world.y;
		if (player->world.x == player->target_world.x
			&& player->world.y == player->target_world.y)
		{
			update_player_pos(player);
			set_idle(player);
			ft_printf("player steps: %i\n", player->move_count);
			player->is_moving = false;
		}
	}
}
