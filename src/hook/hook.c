/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:31:37 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:04:32 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "free_exit.h"
#include "structures.h"
#include "mlx.h"
#include <X11/keysym.h>

int	handle_cross(t_data *data)
{
	free_and_exit_no_error(data);
	return (1);
}

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_and_exit_no_error(data);
	if (keysym == XK_w)
		data->key->w = 1;
	else if (keysym == XK_s)
		data->key->s = 1;
	else if (keysym == XK_a)
		data->key->a = 1;
	else if (keysym == XK_d)
		data->key->d = 1;
	else if (keysym == XK_Left)
		data->key->left = 1;
	else if (keysym == XK_Right)
		data->key->right = 1;
	return (1);
}

int	handle_key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->key->w = 0;
	else if (keysym == XK_s)
		data->key->s = 0;
	else if (keysym == XK_a)
		data->key->a = 0;
	else if (keysym == XK_d)
		data->key->d = 0;
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
