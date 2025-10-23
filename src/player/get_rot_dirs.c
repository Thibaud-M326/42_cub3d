/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:19:00 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/23 14:32:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

double	get_rot_dir_x(double dir_x, double dir_y)
{
	double	rad_angle;
	double	rot_dir_x;

	rad_angle = 1.5708;
	rot_dir_x = dir_x * cos(rad_angle) - dir_y * sin(rad_angle);
	return (rot_dir_x);
}

double	get_rot_dir_y(double dir_x, double dir_y)
{
	double	rad_angle;
	double	rot_dir_y;

	rad_angle = 1.5708;
	rot_dir_y = dir_x * sin(rad_angle) + dir_y * cos(rad_angle);
	return (rot_dir_y);
}
