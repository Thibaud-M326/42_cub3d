/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:37:59 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/08 20:39:19 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdio.h>

static void	handle_error(t_data *data, char c)
{
	if (c == '0')
		free_and_exit(data, MAP_BORDER, 0);
	else
		free_and_exit(data, MAP_PLAYER, 0);
}

int	is_map_valid(t_data *data)
{
	t_map	*m;
	int		y;
	int		line_len;
	int		x;
	char	c;

	m = data->map;
	y = 0;
	while (y < m->height)
	{
		line_len = ft_strlen(m->map[y]);
		x = 0;
		while (x < line_len)
		{
			c = m->map[y][x];
			if (c == '0' || is_player_spawn(c))
			{
				if (y == 0 || y == m->height - 1)
					handle_error(data, c);
				if ((int)ft_strlen(m->map[y - 1]) <= x || m->map[y
					- 1][x] == ' ' || !m->map[y - 1][x])
					handle_error(data, c);
				if ((int)ft_strlen(m->map[y + 1]) <= x || m->map[y
					+ 1][x] == ' ' || !m->map[y + 1][x])
					handle_error(data, c);
				if (x == 0 || m->map[y][x - 1] == ' ' || !m->map[y][x
					- 1])
					handle_error(data, c);
				if (x + 1 >= line_len || m->map[y][x + 1] == ' ' || !m->map[y][x
					+ 1])
					handle_error(data, c);
			}
			x++;
		}
		y++;
	}
	printf("Map ok\n");
	return (1);
}
