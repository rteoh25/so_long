/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:37:02 by rteoh             #+#    #+#             */
/*   Updated: 2024/07/22 08:26:44 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_animations(t_player *player, t_images *imgs)
{
	player->animations[0] = &imgs->player_idle_up;
	player->animations[1] = &imgs->player_idle_down;
	player->animations[2] = &imgs->player_idle_left;
	player->animations[3] = &imgs->player_idle_right;
	player->animations[4] = &imgs->player_move_up;
	player->animations[5] = &imgs->player_move_down;
	player->animations[6] = &imgs->player_move_left;
	player->animations[7] = &imgs->player_move_right;
	player->animations[8] = &imgs->player_death;
}

void	set_enemy_animations(t_enemy *enemy, t_images *imgs)
{
	enemy->animations[0] = &imgs->enemy_idle_up;
	enemy->animations[1] = &imgs->enemy_idle_down;
	enemy->animations[2] = &imgs->enemy_idle_left;
	enemy->animations[3] = &imgs->enemy_idle_right;
	enemy->animations[4] = &imgs->enemy_move_up;
	enemy->animations[5] = &imgs->enemy_move_down;
	enemy->animations[6] = &imgs->enemy_move_left;
	enemy->animations[7] = &imgs->enemy_move_right;
	enemy->animations[8] = &imgs->enemy_death;
}
