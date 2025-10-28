/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:16:31 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/28 18:47:45 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"

static void	update_scroll_row(t_data *data)
{
	t_minimap	*mmap;
	int			player_row;
	int			map_max_row;

	mmap = data->minimap;
	player_row = (int)data->player->pos_y;
	map_max_row = data->map->height - mmap->rows;
	mmap->start_row = player_row - mmap->rows / 2;
	if (map_max_row < 0)
		map_max_row = 0;
	if (mmap->start_row < 0)
		mmap->start_row = 0;
	else if (mmap->start_row > map_max_row)
		mmap->start_row = map_max_row;
}

static void	update_scroll_col(t_data *data)
{
	t_minimap	*mmap;
	int			player_col;
	int			map_max_col;

	mmap = data->minimap;
	player_col = (int)data->player->pos_x;
	map_max_col = data->map->width - mmap->cols;
	mmap->start_col = player_col - mmap->cols / 2;
	if (map_max_col < 0)
		map_max_col = 0;
	if (mmap->start_col < 0)
		mmap->start_col = 0;
	else if (mmap->start_col > map_max_col)
		mmap->start_col = map_max_col;
}

static void	center_minimap(t_data *data)
{
	t_minimap	*mmap;

	mmap = data->minimap;
	mmap->cols = (WIDTH / 6) / mmap->cell_size;
	mmap->rows = (HEIGHT / 6) / mmap->cell_size;
	mmap->start_col = (int)(data->player->pos_x) - mmap->cols / 2;
	mmap->start_row = (int)(data->player->pos_y) - mmap->rows / 2;
	if (mmap->start_col < 0)
		mmap->start_col = 0;
	if (mmap->start_row < 0)
		mmap->start_row = 0;
}

void	update_map(t_data *data)
{
	center_minimap(data);
	update_scroll_row(data);
	update_scroll_col(data);
}
