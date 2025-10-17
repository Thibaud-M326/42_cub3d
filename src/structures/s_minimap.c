/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:38:27 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/17 19:32:44 by jmagand          ###   ########.fr       */
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

	mmap = ft_calloc(1, sizeof(t_minimap));
	if (!mmap)
		free_and_exit(data, MALLOC, 1);
	mmap->start_col = 0;
	mmap->start_row = 0;
	mmap->cols = data->map->height;
	mmap->rows = data->map->width;
	mmap->player_rel_x = 0;
	mmap->player_rel_y = 0;
	mmap->img = ft_calloc(1, sizeof(t_mlx_img));
	if (!mmap->img)
		free_and_exit(data, MALLOC, 1);
	mmap->img->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr, (WIDTH / 5),
			(HEIGHT / 5));
	mmap->img->img_data = mlx_get_data_addr(mmap->img->img_ptr, &mmap->img->bpp,
			&mmap->img->size_line, &mmap->img->endian);
	mmap->img->width = (WIDTH / 5);
	mmap->img->height = (HEIGHT / 5);
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
