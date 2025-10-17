/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:38:27 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/17 21:19:39 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include "minimap.h"
#include "mlx.h"

t_minimap	*init_minimap_struct(t_data *data)
{
	t_minimap	*mmap;
	int			minimap_width_px;
	int			minimap_height_px;

	mmap = ft_calloc(1, sizeof(t_minimap));
	if (!mmap)
		free_and_exit(data, MALLOC, 1);
	mmap->start_col = 0;
	mmap->start_row = 0;
	mmap->cols = (int)((WIDTH / 5) / CELL_SIZE);
	mmap->rows = (int)((HEIGHT / 5) / CELL_SIZE);
	mmap->player_rel_x = 0;
	mmap->player_rel_y = 0;
	mmap->img = ft_calloc(1, sizeof(t_mlx_img));
	if (!mmap->img)
		free_and_exit(data, MALLOC, 1);
	minimap_width_px = mmap->cols * CELL_SIZE;
	minimap_height_px = mmap->rows * CELL_SIZE;
	mmap->img->width = minimap_width_px;
	mmap->img->height = minimap_height_px;
	mmap->img->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr,
			minimap_width_px, minimap_height_px);
	mmap->img->img_data = mlx_get_data_addr(mmap->img->img_ptr, &mmap->img->bpp,
			&mmap->img->size_line, &mmap->img->endian);
	return (mmap);
}

void	free_minimap(t_data *data)
{
	if (data->minimap)
	{
		if (data->minimap && data->minimap->img && data->mlx_data
			&& data->mlx_data->mlx_ptr)
		{
			mlx_destroy_image(data->mlx_data->mlx_ptr,
				data->minimap->img->img_ptr);
		}
		if (data->minimap->img)
			free(data->minimap->img);
		free(data->minimap);
	}
}
