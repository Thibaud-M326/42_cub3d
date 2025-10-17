/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:16:31 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/17 19:40:03 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include "minimap.h"
#include "mlx.h"
#include <stddef.h>

static void	update_scroll_row(t_data *data)
{
	t_minimap	*mmap;
	int			deadzone_pxl;
	int			deadzone_half;
	int			player_y;

	mmap = data->minimap;
	deadzone_pxl = (int)(mmap->rows * CELL_SIZE * DEAD_ZONE_RATIO);
	deadzone_half = deadzone_pxl / 2;
	player_y = (int)((data->player->pos_y - mmap->start_row) * CELL_SIZE);
	if (player_y < deadzone_half)
	{
		mmap->start_row = (int)(data->player->pos_y) - deadzone_pxl / (2
				* CELL_SIZE);
		if (mmap->start_row < 0)
			mmap->start_row = 0;
	}
	else if (player_y > (mmap->rows * CELL_SIZE - deadzone_half))
	{
		mmap->start_row = (int)(data->player->pos_y) - mmap->rows
			+ deadzone_pxl / (2 * CELL_SIZE);
		if (mmap->start_row < 0)
			mmap->start_row = 0;
	}
}

static void	update_scroll_col(t_data *data)
{
	t_minimap	*mmap;
	int			deadzone_pxl;
	int			deadzone_half;
	int			player_x;

	mmap = data->minimap;
	deadzone_pxl = (int)(mmap->cols * CELL_SIZE * DEAD_ZONE_RATIO);
	deadzone_half = deadzone_pxl / 2;
	player_x = (int)((data->player->pos_x - mmap->start_col) * CELL_SIZE);
	if (player_x < deadzone_half)
	{
		mmap->start_col = (int)(data->player->pos_x) - deadzone_pxl / (2
				* CELL_SIZE);
		if (mmap->start_col < 0)
			mmap->start_col = 0;
	}
	else if (player_x > (mmap->cols * CELL_SIZE - deadzone_half))
	{
		mmap->start_col = (int)(data->player->pos_x) - mmap->cols
			+ deadzone_pxl / (2 * CELL_SIZE);
		if (mmap->start_col < 0)
			mmap->start_col = 0;
	}
}

static void	center_minimap(t_data *data)
{
	t_minimap	*mmap;

	mmap = data->minimap;
	mmap->cols = (WIDTH / 5) / CELL_SIZE;
	mmap->rows = (HEIGHT / 5) / CELL_SIZE;
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
