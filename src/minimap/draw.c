/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:16:04 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/29 15:13:28 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"
#include "minimap.h"

static int	handle_char(t_data *data, int color, char c)
{
	t_minimap	*mmap;

	mmap = data->minimap;
	if (c == '1')
		color = WALLS_MMAP;
	else if (c == '0' || c == 'E' || c == 'S' || c == 'W' || c == 'N')
		color = GROUND_MMAP;
	else
		color = VOID_MMAP;
	mmap->player_rel_x = data->player->pos_x - mmap->start_col;
	mmap->player_rel_y = data->player->pos_y - mmap->start_row;
	return (color);
}

static void	draw_map(t_data *data, int i, int map_line, int map_col)
{
	t_minimap	*mmap;
	int			line_len;
	int			j;
	int			color;

	mmap = data->minimap;
	line_len = get_map_line_len(data->map->map[map_line]);
	j = 0;
	while (j < mmap->cols)
	{
		map_col = mmap->start_col + j;
		if (map_col >= line_len)
			break ;
		color = handle_char(data, color, data->map->map[map_line][map_col]);
		if (j == mmap->player_rel_x && i == mmap->player_rel_y)
			color = PLAYER_MMAP;
		draw_cell(data, j * mmap->cell_size, i * mmap->cell_size, color);
		j++;
	}
}

static void	draw_horizontal_borders(t_minimap *mmap, int height, int width)
{
	int	x;

	x = 0;
	while (x < width)
	{
		put_one_pixel_img(mmap->img, x, 0, BORDER_MMAP);
		put_one_pixel_img(mmap->img, x++, 1, BORDER_MMAP);
	}
	x = 0;
	while (x < width)
	{
		put_one_pixel_img(mmap->img, x, height - 1, BORDER_MMAP);
		put_one_pixel_img(mmap->img, x++, height - 2, BORDER_MMAP);
	}
}

static void	draw_borders(t_data *data)
{
	t_minimap	*mmap;
	int			width;
	int			height;
	int			y;

	mmap = data->minimap;
	width = mmap->cols * mmap->cell_size;
	height = mmap->rows * mmap->cell_size;
	draw_horizontal_borders(mmap, height, width);
	y = 0;
	while (y < height)
	{
		put_one_pixel_img(mmap->img, 0, y, BORDER_MMAP);
		put_one_pixel_img(mmap->img, 1, y++, BORDER_MMAP);
	}
	y = 0;
	while (y < height)
	{
		put_one_pixel_img(mmap->img, width - 1, y, BORDER_MMAP);
		put_one_pixel_img(mmap->img, width - 2, y++, BORDER_MMAP);
	}
}

void	draw_minimap(t_data *data)
{
	t_minimap	*mmap;
	int			i;
	int			map_line;
	int			map_col;

	mmap = data->minimap;
	clear_image(mmap->img, VOID_MMAP);
	update_map(data);
	i = 0;
	map_col = 0;
	while (i < mmap->rows)
	{
		map_line = (unsigned int)mmap->start_row + i;
		if (map_line >= data->map->height)
			break ;
		draw_map(data, i, map_line, map_col);
		i++;
	}
	draw_borders(data);
}
