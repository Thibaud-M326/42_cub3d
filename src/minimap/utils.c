/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:17:10 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/27 18:56:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"

int	get_map_line_len(char *line)
{
	int	len;

	len = 0;
	while (line && line[len] && line[len] != '\n')
		len++;
	return (len);
}

int	get_map_max_width(char **map)
{
	int	i;
	int	max_len;
	int	len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		len = get_map_line_len(map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	clear_image(t_mlx_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			put_one_pixel_img(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_cell(t_data *data, int x, int y, int color)
{
	int			i;
	int			j;
	t_minimap	*mmap;

	mmap = data->minimap;
	i = 0;
	while (i < mmap->cell_size)
	{
		j = 0;
		while (j < mmap->cell_size)
		{
			put_one_pixel_img(mmap->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
