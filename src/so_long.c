/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:53:43 by rteoh             #+#    #+#             */
/*   Updated: 2024/07/20 18:59:08 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
if there isnt a .ber file error
so arguments have be 2
*/






int	main(int ac, char **av)
{
	t_game *game;

	if (ac != 2)
		msg(ERR_INPUT);
	game = ft_calloc(1, sizeof(*game));
	if (!game)
		error_msg(ERR_MALLOC);
	parse_mapfile(av[1], &game->map, &game->entity, &game->imgs);
	open_window(game, game->entity.player);
	load_images(game->mlx, &game->imgs);
	mlx_hook
	mlx_loop_hook
	mlx_loop(game->mlx);
}

void	open_window(t_game *game, t_player *player)
{

}