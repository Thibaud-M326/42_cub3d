/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:37:59 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/08 16:59:17 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

int	is_map_valid(t_data *data)
{
	int		y;
	int		x;
	t_map	*m;

	m = data->map;
	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < (int)ft_strlen(m->map[x]))
		{
			if (m->map[y][x] == '0')
			{
				if (y == 0 || y == m->height - 1 || x == 0
					|| x == (int)ft_strlen(m->map[x]) - 1 || m->map[y
					- 1][x] == ' ' || m->map[y + 1][x] == ' ' || m->map[y][x
					- 1] == ' ' || m->map[y][x + 1] == ' ')
					return (0); // Map not closed ?
			}
			x++;
		}
		y++;
	}
	return (1);
}
