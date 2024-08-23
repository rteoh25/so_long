/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:37:02 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/20 23:42:49 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define P_IDLE_DIR_RIGHT "textures/player/idle/right/"
#define P_IDLE_DIR_LEFT "textures/player/idle/left/"
#define P_MOVEMENT_DIR "textures/player/movement/"
#define P_DEATH_DIR "textures/player/ded/"

#define COLLECTIBLE_DIR "textures/collectible/"
#define EXIT_DIR "textures/exit/"
#define FLOOR_DIR "textures/floor/"
#define WALL_DIR "textures/wall/"
#define BACKGROUND_DIR "textures/background/"
#define DIGITS_DIR "textures/digits/"

#define P_IDLE_FRAMES 29
#define P_IDLE_INTERVAL 15

#define P_MOVE_H_FRAMES 4
#define P_MOVE_V_FRAMES 2
#define P_MOVE_H_INTERVAL 5
#define P_MOVE_V_INTERVAL 20

#define P_DEATH_FRAMES 10
#define P_DEATH_INTERVAL 1
/*
define death animation
*/

#define E_IDLE_FRAMES 2
#define E_IDLE_INTERVAL 1

#define E_MOVEMENT_FRAMES 4
#define E_MOVE_INTERVAL 1

/* storing animations into the imgs struct in game struct*/

static void	load_player_animation(void *mlx, t_images *imgs)
{
	imgs->player_idle_left = animate(mlx,
			P_IDLE_DIR_LEFT "cat_idle_left", P_IDLE_FRAMES, P_IDLE_INTERVAL);
	imgs->player_idle_right = animate(mlx,
			P_IDLE_DIR_RIGHT "cat_idle_right", P_IDLE_FRAMES, P_IDLE_INTERVAL);
	imgs->player_move_up = animate(mlx,
			P_MOVEMENT_DIR "up/cat_walking_up",
			P_MOVE_V_FRAMES, P_MOVE_V_INTERVAL);
	imgs->player_move_left = animate(mlx,
			P_MOVEMENT_DIR "left/cat_walking_left",
			P_MOVE_H_FRAMES, P_MOVE_H_INTERVAL);
	imgs->player_move_right = animate(mlx,
			P_MOVEMENT_DIR "right/cat_walking_right",
			P_MOVE_H_FRAMES, P_MOVE_H_INTERVAL);
	imgs->player_move_down = animate(mlx,
			P_MOVEMENT_DIR "down/cat_walking_down",
			P_MOVE_V_FRAMES, P_MOVE_V_INTERVAL);
	imgs->player_death = animate(mlx,
			P_DEATH_DIR "cat_ded", P_DEATH_FRAMES, P_DEATH_INTERVAL);
	imgs->player_death.looping = false;
}

void	load_images(void *mlx, t_images *imgs)
{
	char			*file;
	unsigned int	i;

	imgs->collectible = create_img(mlx, COLLECTIBLE_DIR "collectible_star.xpm");
	imgs->exit = create_img(mlx, EXIT_DIR "door_close.xpm");
	imgs->exit_unlocked = create_img(mlx, EXIT_DIR "door_open.xpm");
	imgs->floor = create_img(mlx, FLOOR_DIR "floor.xpm");
	imgs->walls = create_img(mlx, WALL_DIR "rock_wall.xpm");
	imgs->background = create_img(mlx, BACKGROUND_DIR "grass_background.xpm");
	load_player_animation(mlx, imgs);
	i = 0;
	while (i < NUM_OF_DIGITS)
	{
		file = get_xpm_filepath(DIGITS_DIR "digits", ft_itoa(i));
		imgs->digits[i] = create_img(mlx, file);
		free(file);
		i++;
	}
}

/*initiates the array of animation structs in player*/

void	set_player_animation(t_player *player, t_images *imgs)
{
	player->animations[0] = &imgs->player_idle_left;
	player->animations[1] = &imgs->player_idle_right;
	player->animations[2] = &imgs->player_move_up;
	player->animations[3] = &imgs->player_move_down;
	player->animations[4] = &imgs->player_move_left;
	player->animations[5] = &imgs->player_move_right;
	player->animations[6] = &imgs->player_death;
}
