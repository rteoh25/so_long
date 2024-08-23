/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:10:38 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 14:42:23 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_collectibles(t_collectible *coll)
{
	t_collectible	*tmp;

	while (coll != NULL)
	{
		tmp = coll;
		coll = coll->next;
		free(tmp);
	}
}

void	free_walls(t_wall *wall)
{
	t_wall	*tmp;

	while (wall != NULL)
	{
		tmp = wall;
		wall = wall->next;
		free(tmp);
	}
}

void	free_floor(t_floor *floor)
{
	t_floor	*tmp;

	while (floor != NULL)
	{
		tmp = floor;
		floor = floor->next;
		free(tmp);
	}
}

void	free_animation(void *mlx, t_anim *animation)
{
	unsigned int	i;

	i = 0;
	while (i < animation->num_of_frames)
	{
		mlx_destroy_image(mlx, animation->frames[i]);
		i++;
	}
	free(animation->frames);
}

void	free_player_animation(t_game *game, t_images *imgs)
{
	free_animation(game->mlx, &imgs->player_idle_left);
	free_animation(game->mlx, &imgs->player_idle_right);
	free_animation(game->mlx, &imgs->player_move_down);
	free_animation(game->mlx, &imgs->player_move_left);
	free_animation(game->mlx, &imgs->player_move_right);
	free_animation(game->mlx, &imgs->player_move_up);
	free_animation(game->mlx, &imgs->player_death);
}
