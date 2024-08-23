/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:33:08 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 00:00:50 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_animation_frame(t_anim *curr_anim, unsigned int *ticks)
{
	(*ticks)++;
	if (*ticks >= curr_anim->interval)
	{
		curr_anim->frame_index++;
		if (curr_anim->frame_index >= curr_anim->num_of_frames)
		{
			if (curr_anim->looping)
			{
				curr_anim->frame_index %= curr_anim->num_of_frames;
			}
			else
			{
				curr_anim->frame_index = curr_anim->num_of_frames - 1;
				curr_anim->ended = true;
			}
		}
		*ticks = 0;
	}
}

void	render_player(t_game *game, t_player *player)
{
	void	*frame;

	update_animation_frame(player->current_animation, &player->ticks);
	frame = get_current_frame(player->current_animation);
	put_image(game, frame, player->screen.x, player->screen.y);
}

void	render_digits(t_game *game, t_map *map, t_images *imgs)
{
	int		coll_count;
	int		left_most;
	int		x;
	void	*digit;

	x = 60;
	coll_count = map->collectible_count;
	while (coll_count >= 10)
	{
		left_most = coll_count / 10;
		digit = imgs->digits[left_most];
		put_image(game, digit, x, 0);
		coll_count %= 10;
		x += 40;
	}
	digit = imgs->digits[coll_count];
	put_image(game, digit, x, 0);
}

void	render(t_game *game, t_entity *entities, t_images *imgs)
{
	render_background(game, entities->background, imgs);
	render_walls(game, entities->walls, imgs);
	render_floor(game, entities->floor, imgs);
	render_exit(game, entities->exit, imgs);
	render_collectible(game, entities->collectible, imgs);
	render_digits(game, &game->map, imgs);
	render_player(game, entities->player);
}
