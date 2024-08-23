/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:55:41 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 19:06:15 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define ERR_INPUT "Bad Arguments:\nEXAMPLE: ./so_long <filename>.ber\n"
# define ERR_MALLOC "MALLOC_ERROR"
# define ERR_FILE "Invalid file"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define B_TILE_WIDTH 260
# define B_TILE_HEIGHT 275

# define DESTROY_WINDOW 17
# define KEY_PRESSED 2

/*
size of window x 1100, y 800
top left = x: -64 | y : -64
top left = x: 910 | y : -64
bottom right = x: 910 | y : 620

distance for 2 tiles to be next to each other is 126 x and y
						________________________
	x = -64, y = -64	|						| x = 910 y = -64
						|						|
						|						|
						|						|
						|						|
						|						|
						|						|
	x = -64, y = 620	|_______________________| x = 910 y = 620
*/

# define TILE_HEIGHT 80
# define TILE_WIDTH 80

# define PLAYER_STATES 7
# define ENEMY_STATES 4

# define STEP_SIZE 4

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
	IDLE_LEFT = 0,
	IDLE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	DEAD
}	t_state;

enum e_keys
{
	UP_KEY = 13,
	LEFT_KEY = 0,
	DOWN_KEY = 1,
	RIGHT_KEY = 2,
	ESC_KEY = 53
};

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_hitbox
{
	t_position	top_left;
	t_position	bot_right;
}	t_hitbox;

typedef struct s_anim
{
	unsigned int	num_of_frames;
	unsigned int	interval;
	void			**frames;
	unsigned int	frame_index;
	bool			looping;
	bool			ended;
}	t_anim;

# define NUM_OF_DIGITS 10

typedef struct s_images
{
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*exit_unlocked;
	void	*digits[NUM_OF_DIGITS];
	void	*background;
	void	*walls;
	t_anim	player_idle_left;
	t_anim	player_idle_right;
	t_anim	player_move_up;
	t_anim	player_move_right;
	t_anim	player_move_down;
	t_anim	player_move_left;
	t_anim	player_death;
	t_anim	enemy_idle_left;
	t_anim	enemy_idle_right;
	t_anim	enemy_move_right;
	t_anim	enemy_move_left;
}	t_images;

typedef struct s_visited
{
	t_position			tile;
	struct s_visited	*next;
}	t_visited;

typedef struct s_queue
{
	t_position		tile;
	struct s_queue	*next;
}	t_queue;

typedef struct s_map
{
	unsigned int			height;
	unsigned int			width;
	int						collectible_count;
	int						player_count;
	int						exit_count;
	char					**layout;
	t_visited				*visited;
	t_queue					*queue;
}	t_map;

typedef struct s_background
{
	t_position			screen;
	struct s_background	*next;
}	t_background;

typedef struct s_wall
{
	t_position		tile;
	t_position		world;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	t_position		screen;
	struct s_wall	*next;
}	t_wall;

typedef struct s_floor
{
	t_position		tile;
	t_position		world;
	t_position		screen;
	struct s_floor	*next;
}	t_floor;

typedef struct s_collectible
{
	struct s_collectible	*prev;
	t_position				tile;
	t_position				world;
	t_position				screen;
	t_hitbox				hitbox;
	struct s_collectible	*next;
}	t_collectible;

typedef struct s_player
{
	t_position		tile;
	t_position		world;
	t_position		target_world;
	t_position		screen;
	t_state			state;
	t_hitbox		hitbox;
	unsigned int	ticks;
	unsigned int	move_count;
	bool			is_moving;
	t_anim			*current_animation;
	t_anim			*animations[PLAYER_STATES];
}	t_player;

typedef struct s_enemy
{
	t_position		tile;
	t_position		world;
	t_position		target_world;
	t_state			state;
	t_hitbox		hitbox;
	bool			is_moving;
	unsigned int	ticks;
	t_anim			*current_animation;
	t_anim			*animations[ENEMY_STATES];
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_exit
{
	bool		is_unlocked;
	t_position	tile;
	t_position	world;
	t_position	screen;
	t_hitbox	hitbox;
}	t_exit;

typedef struct s_entity
{
	t_player		*player;
	t_enemy			*enemy;
	t_wall			*walls;
	t_floor			*floor;
	t_collectible	*collectible;
	t_exit			*exit;
	t_background	*background;
}	t_entity;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_entity	entity;
	t_images	imgs;
	t_map		map;
	t_position	offset;
	t_position	bg_offset;
}	t_game;

void		error_msg(char *err);
void		msg(char *err);

/*exit*/
int			exit_game(t_game *game);

/*free*/
void		free_layout(char **layout, unsigned int map_height);
void		free_collectibles(t_collectible *coll);
void		free_walls(t_wall *wall);
void		free_floor(t_floor *floor);
void		free_animation(void *mlx, t_anim *animation);
void		free_player_animation(t_game *game, t_images *imgs);

void		update_player(t_game *game, t_player *player);

/*game_loop*/
void		*get_current_frame(t_anim *animation);
void		render_background(t_game *game, t_background *bg, t_images *imgs);
void		render_walls(t_game *game, t_wall *wall, t_images *imgs);
void		render_floor(t_game *game, t_floor *floor, t_images *imgs);
void		render_collectible(t_game *game, t_collectible *collectible,
				t_images *imgs);
void		render_exit(t_game *game, t_exit *exit, t_images *imgs);
void		render_digits(t_game *game, t_map *map, t_images *imgs);
void		render_player(t_game *game, t_player *player);
void		render(t_game *game, t_entity *entities, t_images *imgs);

/*move*/
void		move_left(t_player *player);
void		move_right(t_player *player);
void		move_up(t_player *player);
void		move_down(t_player *player);
void		move_player_step(t_player *player);

/*hitbox*/
bool		entities_collide(t_hitbox *entity1, t_hitbox *entity2);
void		set_idle(t_player *player);
void		set_idle(t_player *player);
void		update_player_pos(t_player *player);

t_hitbox	set_hitbox(t_position	*world);

char		*get_xpm_filepath(const char *filepath, char *count);
void		*create_img(void *mlx, char *xpm_file);
void		put_image(t_game *game, void *img, int x, int y);
t_anim		animate(void *mlx, const char *filepath, unsigned int frame_count,
				int interval);
void		load_images(void *mlx, t_images *imgs);
void		set_player_animation(t_player *player, t_images *imgs);
void		set_enemy_animation(t_enemy *enemy, t_images *imgs);

bool		is_movement(int keycode);
bool		is_wall(char c);
int			move_player(int keycode, t_game *game);

void		set_pos(t_position *tile, t_position *world, t_position *pos);
void		init_player(t_position *tile,
				t_entity *entities, t_map *map, t_images *imgs);
void		init_enemy(t_position *tile, t_entity *entities, t_images *imgs);
void		init_exit(t_position *tile, t_entity *entities, t_map *map);
void		init_walls(t_position *tile, t_entity	*entities);
void		init_floors(t_position *tile, t_entity	*entities);
void		init_collectibles(t_position *tile,
				t_entity *entities, t_map *map);
void		init_game_entities(char *row,
				t_entity *entities, t_map *map, t_images *imgs);
void		free_visited(t_visited **visited);

/*path_checking*/
int			is_tile_visited(t_visited *visited, t_position *tile);
int			is_tile_queued(t_queue *queue, t_position *tile);
void		free_visited(t_visited **visited);
void		update_visited(t_map *map, t_position *pos);
t_queue		*update_queue(t_queue **queue);
void		check_valid_path(t_map *map, t_position *pos, char **layout);
void		validate_map(t_map *map, t_player *player);

void		parse_map(const char *file, t_map *map,
				t_entity *entities, t_images *imgs);

/*images*/
void		*create_img(void *mlx, char *xpm_file);
t_anim		animate(void *mlx, const char *filepath, unsigned int frame_count,
				int interval);

#endif