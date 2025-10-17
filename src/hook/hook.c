/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:31:37 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/17 19:08:23 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	handle_cross(t_data *data)
{
	free_and_exit(data, "", 0);
	return (1);
}

int	handle_keyboard(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_and_exit(data, "", 0);
	return (1);
}

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_and_exit(data, "", 0);
	if (keysym == XK_Up)
		data->key->up = 1;
	else if (keysym == XK_Down)
		data->key->down = 1;
	else if (keysym == XK_Left)
		data->key->left = 1;
	else if (keysym == XK_Right)
		data->key->right = 1;
	return (1);
}

int	handle_key_release(int keysym, t_data *data)
{
	if (keysym == XK_Up)
		data->key->up = 0;
	else if (keysym == XK_Down)
		data->key->down = 0;
	else if (keysym == XK_Left)
		data->key->left = 0;
	else if (keysym == XK_Right)
		data->key->right = 0;
	return (1);
}

int	deploy_mlx_hook(t_data *data)
{
	mlx_hook(data->mlx_data->win_ptr, 17, 0L, &handle_cross, data);
	mlx_hook(data->mlx_data->win_ptr, 02, 1L << 0, &handle_key_press, data);
	mlx_hook(data->mlx_data->win_ptr, 03, 1L << 1, &handle_key_release, data);
	mlx_loop_hook(data->mlx_data->mlx_ptr, render, data);
	mlx_loop(data->mlx_data->mlx_ptr);
	return (1);
}
