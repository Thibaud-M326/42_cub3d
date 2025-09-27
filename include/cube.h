/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/27 22:39:59 by vscode           ###   ########.fr       */
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
int	mlx_start(t_mlx_data *mlx_data, t_mlx_img *mlx_img);

#endif
