/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:31:37 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/01 18:45:07 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"

int	handle_cross(t_data *data)
{
	free_and_exit(data, (t_msg)"", 0);
	return (0);
}

int deploy_mlx_hook(t_data *data)
{
	mlx_hook(data->mlx_data->win_ptr, 17, 0L, &handle_cross, data);
	mlx_loop(data->mlx_data->mlx_ptr);
	return (1);
}