/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:49:03 by rteoh             #+#    #+#             */
/*   Updated: 2024/07/22 10:53:37 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
open file
check whether map is valid, if each row is the same,
initiate the entities
get_rows and put them in layout in t_map;
*/

static int	open_mapfile(const char *file)
{
	int	fd;

	fd = open(fd, O_RDONLY);
	if (fd < 0)
		error_msg(ERR_FILE);
	if (ft_strend(file, ".ber") == 0)
	{
		close(fd);
		error_msg("Map is not .ber file\n");
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
	rows = malloc(sizeof(*rows) * map->height);
	if (!rows)
		error_msg(ERR_MALLOC);
	while (i <map->height - 1)
	{
		rows[i] = map->layout[i];
		i++;
	}
	free(map->layout);
	rows[map->height - 1] = row;
	map->layout = rows;
}


void	parse_map(const char *file, t_map *map, t_entity *entities, t_images *imgs)
{
	int		fd;
	char	*row;

	fd = open_mapfile(file);
	row = get_next_row(fd);
	if (!row)
		msg_error(ERR_MALLOC);
	map->width = ft_strlen(row);
	while (row)
	{
		if (ft_strlen(row) != map->width)
			msg("map is not straight");
		map->height++;
		init_game_entities(row, entities, map, imgs);
		store_map_layout(map, row);
		row = get_next_row(fd);
	}
	close(fd);
	validate_map(map, entities->player);
	init_background(&entities->background);
}
