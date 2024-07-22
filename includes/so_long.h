/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:55:41 by rteoh             #+#    #+#             */
/*   Updated: 2024/07/22 13:03:17 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>

# define ERR_INPUT "Bad Arguments:\nEXAMPLE: ./so_long <filename>.ber\n"
# define ERR_MALLOC "MALLOC_ERROR"
# define ERR_FILE "Invalid file"

# define TILE_HEIGHT 64
# define TILE_WIDTH 64

# define PLAYER_STATES 9


typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_entity	*entity;
	t_images	*imgs;
	t_map		*map;
	t_position	offset;
}	t_game;

typedef	struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	int	height;
	int	width;
	int	collectible_count;
	int	player_count;
	int	exit_count;
	char **layout;
}	t_map;

typedef enum e_map_elem
{
	FLOOR = '0',
	WALL = '1',
	PLAYER = 'P',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	ENEMY = 'M'
}	t_map_elem;

typedef enum e_state
{
	IDLE_UP = 0,
	IDLE_DOWN,
	IDLE_LEFT,
	IDLE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	DEAD
}	t_state;


typedef	struct s_background
{
	t_position		screen;
	struct s_background	*next;
}	t_background;

typedef	struct s_wall
{
	t_position		tile;
	t_position		world;
	t_position		screen;
	struct s_wall	*next
}	t_wall;

typedef	struct s_floor
{
	t_position		tile;
	t_position		world;
	t_position		screen;
	struct s_floor	*next;
}	t_floor;

typedef	struct s_collectible
{
	t_position				tile;
	t_position				world;
	t_position				screen;
	struct s_collectible	*next;
}	t_collectible;

typedef	struct s_entity
{
	t_player		*player;
	t_enemy			*enemy;
	t_wall			*walls;
	t_floor			*floor;
	t_collectible	*collectible;
	t_exit			*exit;
	t_background	*background;
}	t_entity;

typedef struct s_hitbox
{
	t_position	top_left;
	t_position	bot_right;
}	t_hitbox;

typedef	struct s_player
{
	t_position	tile;
	t_position	world;
	t_position	target_world;
	t_state		state;
	t_hitbox	hitbox;
	unsigned int	ticks;
	unsigned int	move_count;
	t_anim			*current_animation;
	t_anim			*animations[PLAYER_STATES];

}	t_player;

typedef	struct s_enemy
{
	t_position	tile;
	t_position	world;
	t_position	target_world;
	t_state		state;
	t_hitbox	hitbox;
	bool		is_moving;
	unsigned int	ticks;
	t_anim			*current_animation;
	t_anim			*animations[PLAYER_STATES];
	struct s_enemy	*next;
}	t_enemy;

typedef	struct s_exit
{
	t_position	tile;
	t_position	world;
	t_hitbox	hitbox;
	bool		unlocked;
}	t_exit;

typedef	struct s_images
{
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*exit_unlocked;
	t_anim	background;
	t_anim	walls;
	t_anim	player_idle_up;
	t_anim	player_idle_left;
	t_anim	player_idle_right;
	t_anim	player_idle_down;
	t_anim	player_move_up;
	t_anim	player_move_right;
	t_anim	player_move_down;
	t_anim	player_move_left;
	t_anim	player_death;
	t_anim	enemy_idle_up;
	t_anim	enemy_idle_left;
	t_anim	enemy_idle_right;
	t_anim	enemy_idle_down;
	t_anim	enemy_move_up;
	t_anim	enemy_move_down;
	t_anim	enemy_move_right;
	t_anim	enemy_move_left;
	t_anim	enemy_death;
}	t_images;

typedef	struct s_anim
{
	unsigned int	num_of_frames;
	unsigned int	interval;
	void			**frams;
	unsigned int	frame_index;
	bool			looping;
	bool			ended;
}	t_anim;


int		msg(char *err);
void	error_msg(char *err);

#endif