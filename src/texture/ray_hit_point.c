/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:01:29 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:17:51 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

int	ray_hit_point(t_data *data)
{
	t_player	*p;

	p = data->player;
	p->ray.hit_pos_x = p->pos_x + (p->ray.dir_x * p->ray.distance);
	p->ray.hit_pos_y = p->pos_y + (p->ray.dir_y * p->ray.distance);
	return (1);
}
