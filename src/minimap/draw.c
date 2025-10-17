/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:16:04 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/17 19:36:08 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "minimap.h"
#include "mlx.h"

// static void	draw_horizontal_borders(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int	end_x;
// 	int	end_y;
// 	int	start_x;

// 	start_x = WIDTH / 30;
// 	end_x = (WIDTH / 5) / CELL_SIZE;
// 	end_y = (HEIGHT / 5) / CELL_SIZE;
// 	y = HEIGHT / 30;
// 	x = start_x;
// 	while (x < end_x)
// 	{
// 		put_one_pixel_img(data->minimap->img, x, y, BORDER_MMAP);
// 		x++;
// 	}
// 	x = start_x;
// 	y = end_y - 1;
// 	while (x < end_x)
// 	{
// 		put_one_pixel_img(data->minimap->img, x, y, BORDER_MMAP);
// 		x++;
// 	}
// }

// static void	draw_vertical_borders(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int	end_x;
// 	int	end_y;
// 	int	start_y;

// 	start_y = HEIGHT / 30;
// 	end_x = (WIDTH / 5) / CELL_SIZE;
// 	end_y = (HEIGHT / 5) / CELL_SIZE;
// 	x = WIDTH / 30;
// 	y = start_y;
// 	while (y < end_y)
// 	{
// 		put_one_pixel_img(data->minimap->img, x, y, BORDER_MMAP);
// 		y++;
// 	}
// 	x = end_x - 1;
// 	y = start_y;
// 	while (y < end_y)
// 	{
// 		put_one_pixel_img(data->minimap->img, x, y, BORDER_MMAP);
// 		y++;
// 	}
// }

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
		draw_cell(mmap->img, j * CELL_SIZE, i * CELL_SIZE, color);
		j++;
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
}
