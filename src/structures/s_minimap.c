/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:38:27 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/21 18:27:53 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include "minimap.h"
#include "mlx.h"

static t_mlx_img	*init_minimap_img(t_data *data)
{
	t_minimap	*mmap;
	t_mlx_img	*img;
	int			minimap_w_pxl;
	int			minimap_h_pxl;

	mmap = data->minimap;
	img = ft_calloc(1, sizeof(t_mlx_img));
	if (!img)
		free_and_exit(data, MALLOC, 1);
	minimap_w_pxl = mmap->cols * mmap->cell_size;
	minimap_h_pxl = mmap->rows * mmap->cell_size;
	img->width = minimap_w_pxl;
	img->height = minimap_h_pxl;
	img->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr, minimap_w_pxl,
			minimap_h_pxl);
	img->img_data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	return (img);
}

static t_mlx_img	*init_background_img(t_data *data)
{
	t_minimap	*mmap;
	t_mlx_img	*background_img;

	mmap = data->minimap;
	background_img = ft_calloc(1, sizeof(t_mlx_img));
	if (!background_img)
		free_and_exit(data, MALLOC, 1);
	background_img->width = mmap->img->width + 5;
	background_img->height = mmap->img->height + 5;
	background_img->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr,
			background_img->width, background_img->height);
	background_img->img_data = mlx_get_data_addr(background_img->img_ptr,
			&background_img->bpp, &background_img->size_line,
			&background_img->endian);
	return (background_img);
}

static int	choose_cell_size(t_data *data)
{
	int	map_width;
	int	cell_size_w;
	int	cell_size_h;
	int	cell_size;

	map_width = get_map_max_width(data->map->map);
	if (map_width > 0)
		cell_size_w = (WIDTH / 6) / map_width;
	else
		cell_size_w = CELL_SIZE_MIN;
	if (data->map->height > 0)
		cell_size_h = (HEIGHT / 6) / data->map->height;
	else
		cell_size_h = CELL_SIZE_MIN;
	if (cell_size_w < cell_size_h)
		cell_size = cell_size_w;
	else
		cell_size = cell_size_h;
	if (cell_size < CELL_SIZE_MIN)
		cell_size = CELL_SIZE_MIN;
	else if (cell_size > CELL_SIZE_MAX)
		cell_size = CELL_SIZE_MAX;
	return (cell_size);
}

t_minimap	*init_minimap_struct(t_data *data)
{
	t_minimap	*mmap;

	mmap = ft_calloc(1, sizeof(t_minimap));
	if (!mmap)
		free_and_exit(data, MALLOC, 1);
	mmap->start_col = 0;
	mmap->start_row = 0;
	mmap->player_rel_x = 0;
	mmap->player_rel_y = 0;
	data->minimap = mmap;
	mmap->cell_size = choose_cell_size(data);
	mmap->cols = (WIDTH / 6) / mmap->cell_size;
	mmap->rows = (HEIGHT / 6) / mmap->cell_size;
	mmap->img = init_minimap_img(data);
	mmap->background = init_background_img(data);
	return (mmap);
}

void	free_minimap(t_data *data)
{
	if (data->minimap)
	{
		if (data->mlx_data && data->mlx_data->mlx_ptr)
		{
			if (data->minimap && data->minimap->img)
			{
				mlx_destroy_image(data->mlx_data->mlx_ptr,
					data->minimap->img->img_ptr);
			}
			if (data->minimap && data->minimap->background)
			{
				mlx_destroy_image(data->mlx_data->mlx_ptr,
					data->minimap->background->img_ptr);
			}
		}
		if (data->minimap->img)
			free(data->minimap->img);
		free(data->minimap);
	}
}
