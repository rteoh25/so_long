/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:49:03 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 15:06:59 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
open file
check whether map is valid, if each row is the same,
initiate the entities.
get_rows and put them in layout in t_map;
*/

static int	open_mapfile(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_msg(ERR_FILE);
	if (ft_strend((char *)file, ".ber") == 0)
	{
		close(fd);
		msg("Map is not .ber file\n");
	}
	return (fd);
}

static char	*get_next_row(int fd)
{
	char	*line;
	char	*row;

	line = get_next_line(fd);
	row = ft_strtrim(line, "\n");
	free(line);
	return (row);
}

static void	store_map_layout(t_map *map, char *row)
{
	unsigned int	i;
	char			**rows;

	i = 0;
	rows = malloc(sizeof(*rows) * (map->height));
	if (!rows)
		error_msg(ERR_MALLOC);
	while (i < map->height - 1)
	{
		rows[i] = map->layout[i];
		i++;
	}
	free(map->layout);
	rows[map->height - 1] = row;
	map->layout = rows;
}

void	init_background(t_background **bg)
{
	t_background	*bg_tile;
	t_background	**curr_ptr;
	int				x;
	int				y;

	curr_ptr = bg;
	y = -B_TILE_HEIGHT;
	while (y < WIN_HEIGHT + B_TILE_HEIGHT)
	{
		x = -B_TILE_WIDTH;
		while (x < WIN_WIDTH + B_TILE_WIDTH)
		{
			bg_tile = malloc(sizeof(*bg_tile));
			bg_tile->screen.x = x;
			bg_tile->screen.y = y;
			bg_tile->next = NULL;
			while (*curr_ptr != NULL)
				curr_ptr = &(*curr_ptr)->next;
			*curr_ptr = bg_tile;
			x += B_TILE_WIDTH;
		}
		y += B_TILE_HEIGHT;
	}
}

void	parse_map(const char *file, t_map *map,
					t_entity *entities, t_images *imgs)
{
	int		fd;
	char	*row;

	fd = open_mapfile(file);
	row = get_next_row(fd);
	if (!row)
		msg("Map is empty like me");
	map->width = ft_strlen(row);
	while (row != NULL)
	{
		if (ft_strlen(row) != map->width)
			msg("Map is not rectangle?");
		map->height++;
		init_game_entities(row, entities, map, imgs);
		store_map_layout(map, row);
		row = get_next_row(fd);
	}
	close(fd);
	validate_map(map, entities->player);
	init_background(&entities->background);
}
