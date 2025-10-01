/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:31:37 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/01 20:58:22 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <X11/keysym.h>

int	handle_cross(t_data *data)
{
	free_and_exit(data, msg_custom(""), 0);
	return (0);
}

int	handle_keyboard(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_and_exit(data, msg_custom(""), 0);
	else if (keysym == XK_Left)
		player_move_left(data);
	else if (keysym == XK_Right)
		player_move_right(data);
	else if (keysym == XK_Up)
		player_move_up(data);
	else if (keysym == XK_Down)
		player_move_down(data);
	return (0);
}

int deploy_mlx_hook(t_data *data)
{
	mlx_hook(data->mlx_data->win_ptr, 17, 0L, &handle_cross, data);
	mlx_key_hook(data->mlx_data->win_ptr, &handle_keyboard, data);
	mlx_loop_hook(data->mlx_data->mlx_ptr, render, data);
	mlx_loop(data->mlx_data->mlx_ptr);
	return (1);
}