/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:09:46 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/29 15:36:52 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "render.h"
#include "libft.h"
#include "mlx.h"

int	print_fps(t_data *data, double fps_count)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	char	*fps_framerate;

	mlx_ptr = data->mlx_data->mlx_ptr;
	win_ptr = data->mlx_data->win_ptr;
	x = WIDTH - WIDTH / 23;
	y = HEIGHT / 23;
	fps_framerate = ft_itoa((int)(1 / fps_count));
	mlx_string_put(mlx_ptr, win_ptr, x, y, 0xFF0000, fps_framerate);
	return (1);
}

int	fps_count(t_data *data)
{
	data->fps->old_time = data->fps->time;
	data->fps->time = get_current_time_ms();
	data->fps->fps_count = (data->fps->time - data->fps->old_time) / 1000.0;
	data->fps->move_speed = data->fps->fps_count * 3.0;
	data->fps->rot_speed = data->fps->fps_count * 2.0;

	print_fps(data, data->fps->fps_count);

	return (1);
}
