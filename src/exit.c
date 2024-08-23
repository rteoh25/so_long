/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:47:25 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 15:47:18 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_layout(char **layout, unsigned int map_height)
{
	unsigned int	i;

	i = 0;
	while (i < map_height)
	{
		free(layout[i]);
		i++;
	}
	free(layout);
}

static void	free_game(t_game *game, t_images *imgs,
					t_entity *entities)
{
	int	i;

	mlx_destroy_image(game->mlx, imgs->floor);
	mlx_destroy_image(game->mlx, imgs->walls);
	mlx_destroy_image(game->mlx, imgs->collectible);
	mlx_destroy_image(game->mlx, imgs->exit);
	mlx_destroy_image(game->mlx, imgs->exit_unlocked);
	free_player_animation(game, imgs);
	free_layout(game->map.layout, game->map.height);
	i = 0;
	while (i < NUM_OF_DIGITS)
	{
		mlx_destroy_image(game->mlx, imgs->digits[i]);
		i++;
	}
	free_collectibles(entities->collectible);
	free_walls(entities->walls);
	free_floor(entities->floor);
	free(entities->player);
	free(entities->exit);
}

int	exit_game(t_game *game)
{
	t_player const	*player = game->entity.player;

	mlx_destroy_window(game->mlx, game->win);
	free_game(game, &game->imgs, &game->entity);
	ft_printf("player steps: %i\n", player->move_count);
	ft_putstr_fd("GAME FINISHED\n", 1);
	exit (EXIT_SUCCESS);
}
