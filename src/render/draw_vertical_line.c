/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:12:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/14 19:38:32 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_vert(t_data *data, int x, int line_start, int line_end, int color)
{
	while (line_start < line_end)
	{
		put_one_pixel(data, x, line_start, color);
		line_start++;
	}
	return (1);
}

int	ray_hit_point(t_data *data)
{
	
	return (1);
}

//je veut trouver quel couleur je dois appliquer a chaque texture de mon mur
//actuellement j'ai le rayon, sa direction, son point de depart et sa longueur
//je dois trouver ou touche le rayon exactement
//si je fait le cacul du vecteur je devrais trouver ou il arrive
//une fois que je sais ou le rayon arrive je dois lui retirer la partie entiere
//pour ne garder que la fraction.
int	draw_vertical_line(t_data *data, int x)
{
	t_ray	*ray;
	int		line_h;
	int		line_start;
	int		line_end;
	int		color;

	color = 0x3ED6D2;
	ray = &data->player->ray;
	
	line_h = 1000 / ray->distance;
	line_start = -line_h / 2 + 1000 / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = line_h / 2 + 1000 / 2;
	if (line_end >= 1000)
		line_end = 1000 - 1;
	if (ray->side == 1)
		color /= 2;
	draw_vert(data, x, line_start, line_end, color);
	return (1);
}
