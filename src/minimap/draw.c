/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:16:04 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/21 17:56:14 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "minimap.h"
#include "mlx.h"

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
		{
			j++;
			continue ;
		}
		color = handle_char(data, color, data->map->map[map_line][map_col]);
		if (j == mmap->player_rel_x && i == mmap->player_rel_y)
			color = PLAYER_MMAP;
		draw_cell(data, j * mmap->cell_size, i * mmap->cell_size, color);
		j++;
	}
}

static void	draw_background(t_data *data)
{
	int	col;
	int	row;

	row = 0;
	while (row < data->minimap->background->height)
	{
		col = 0;
		while (col < data->minimap->background->width)
		{
			put_one_pixel_img(data->minimap->background, col, row, BORDER_MMAP);
			col++;
		}
		row++;
	}
}

void	draw_minimap(t_data *data)
{
	t_minimap	*mmap;
	int			i;
	int			map_line;
	int			map_col;

	mmap = data->minimap;
	draw_background(data);
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
}
