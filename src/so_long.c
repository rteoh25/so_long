/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:53:43 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 11:51:54 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
if there isnt a .ber file error
so arguments have be 2
*/

void	open_window(t_game *game, t_player *player)
{
	game->mlx = mlx_init();
	player->screen.x = 335;
	player->screen.y = 237;
	game->offset.x = player->screen.x - player->world.x;
	game->offset.y = player->screen.y - player->world.y;
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "SO_LONG");
}

int	game_loop(t_game *game)
{
	t_entity *const	entities = &game->entity;

	mlx_clear_window(game->mlx, game->win);
	update_player(game, entities->player);
	render(game, &game->entity, &game->imgs);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_msg(ERR_INPUT);
	game = (t_game){0};
	parse_map(av[1], &game.map, &game.entity, &game.imgs);
	open_window(&game, game.entity.player);
	load_images(game.mlx, &game.imgs);
	mlx_hook(game.win, KEY_PRESSED, 0, move_player, &game);
	mlx_hook(game.win, DESTROY_WINDOW, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
