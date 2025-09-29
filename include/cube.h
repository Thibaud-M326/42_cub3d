/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/29 19:58:48 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

	#include <stdio.h>

typedef struct s_mlx_img
{
	void	*img_ptr;
	char	*img_data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	*mlx_img;
	int			color;
}	t_mlx_data;

//src/init.c
int		mlx_start(t_mlx_data *mlx_data, t_mlx_img *mlx_img);

//src/render/render.c
int		render(t_mlx_data *data);

//src/render/draw.c
void	put_one_pixel(t_mlx_img *mlx_img, int x, int y, int color);
int		mix_color(int red, int green, int blue);

#endif
