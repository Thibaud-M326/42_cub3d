/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:56:57 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/09 16:08:42 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdlib.h>

int	**create_map(void)
{
	int	**map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	map = malloc(sizeof(int *) * 10);
	if (!map)
		return (NULL);
	while (i < 10)
	{
		map[i] = malloc(sizeof(int) * 10);
		if (!map[i])
		{
			while (--i >= 0)
			{
				free(map[i]);
				return (NULL);
			}
		}
		i++;
	}
	int temp_map[10][10] = {
		{ 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			map[i][j] = temp_map[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

int init_cub2d(t_data *data)
{
	int			**map;

	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (0);
	map = create_map();
    data->map->map = map;
    return (1);
}