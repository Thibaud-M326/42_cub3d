/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_xpm_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:18:28 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/13 18:10:38 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"

	#include <stdio.h>

int	print_color_to_img(t_data *data, int color)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			put_one_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
	return (1);
}

int	get_color_from_texture(t_mlx_img *tex, int x, int y)
{
	int	byte;
	int	pixel_index;
	int	tex_pixel_color;

	byte = 8;
	pixel_index = (tex->size_line * y) + ((tex->bits_per_pixel / byte) * x);
	tex_pixel_color = *(int *)&(tex->img_data[pixel_index]);
	return (tex_pixel_color);
}

/*

//	256 ÷ (32 ÷ 8)
//	size_line / (bits_per_pixel / (1 byte)) = width

donc si je veut la couleur du byte en y = 5 et x = 3

je dois faire me deplacer dans la string des donne en faisant le calcul de combien
de pixel je dois avancer pour toucher le debut du bon premier pixel

deja juste pour y = 0 et x = 3

tex_y = size_line * y + 1;
tex_x = tex_y + (bits_per_pixel / (1 bytes)) * x;

les 32 bits per pixel suivant represente la couleur du pixel voulu

comment je fait pour recuperer les couleurs

j'avance de 1 je stock le bit dans un int, 

*/

int	get_color_from_xpm_file(t_data *data)
{
	char		*tex_path = "./assets/textures/walls/test_1.xpm";
	t_mlx_img	tex;
	int			tex_pix_color;


	tex.img_ptr = mlx_xpm_file_to_image(
			data->mlx_data->mlx_ptr,
			tex_path,
			&tex.width,
			&tex.height);
	if (!tex.img_ptr)
	{
		printf("mlx_xpm_file_to_image_failed\n");
		return (0);
	}

	tex.img_data = mlx_get_data_addr(
			tex.img_ptr,
			&tex.bits_per_pixel,
			&tex.size_line,
			&tex.endian);

	tex_pix_color = get_color_from_texture(&tex, 3, 2);
	print_color_to_img(data, tex_pix_color);

	mlx_put_image_to_window (
		data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr,
		data->mlx_data->mlx_img->img_ptr,
		0,
		0);
	
	mlx_put_image_to_window (
		data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr,
		tex.img_ptr,
		0,
		0);
	return (1);
}
