/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:56:22 by rteoh             #+#    #+#             */
/*   Updated: 2024/08/21 12:46:08 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_current_frame(t_anim *animation)
{
	return (animation->frames[animation->frame_index]);
}

void	*create_img(void *mlx, char *xpm_file)
{
	int	img_width;
	int	img_height;

	return (mlx_xpm_file_to_image(mlx, xpm_file, &img_width, &img_height));
}

void	put_image(t_game *game, void *img, int x, int y)
{
	if (img == NULL)
	{
		perror("img not found");
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

char	*get_xpm_filepath(const char *filepath, char *count)
{
	char	*xpm_filepath;
	char	*count_xpm;
	size_t	len;

	len = ft_strlen(filepath) + ft_strlen(".xpm") + 1;
	count_xpm = ft_strjoin(count, ".xpm");
	xpm_filepath = ft_strjoin(filepath, count_xpm);
	free(count_xpm);
	free(count);
	return (xpm_filepath);
}

/* putting all the animation frames into an array in imgs*/

t_anim	animate(void *mlx, const char *filepath, unsigned int frame_count,
int interval)
{
	t_anim			animation;
	void			**frames;
	char			*file;
	unsigned int	i;

	frames = malloc(sizeof(*frames) * frame_count);
	if (frames == NULL)
		error_msg(ERR_MALLOC);
	i = 0;
	while (i < frame_count)
	{
		file = get_xpm_filepath(filepath, ft_itoa(i + 1));
		frames[i] = create_img(mlx, file);
		free(file);
		i++;
	}
	animation.num_of_frames = frame_count;
	animation.frame_index = 0;
	animation.interval = interval;
	animation.frames = frames;
	animation.looping = true;
	animation.ended = false;
	return (animation);
}
