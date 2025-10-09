/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:48:39 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/09 20:12:48 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


void	print_player(t_data *data)
{
#include <stdio.h>
	printf("\npos_x: %d\n", data->player->pos_x);
	printf("pos_y: %d\n", data->player->pos_y);
	printf("id: %c\n", data->player->id);
}

void	print_textures(t_data *data)
{
#include <stdio.h>
	printf("\nNORTH: %s\n", data->textures->path_n);
	printf("SOUTH: %s\n", data->textures->path_s);
	printf("WEST: %s\n", data->textures->path_w);
	printf("EAST: %s\n\n", data->textures->path_e);
	printf("FLOOR: %d\n", data->textures->floor_color);
	printf("CEIL: %d\n\n", data->textures->ceil_color);
	printf("MAP: %s\n\n", data->file->map);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		printf("\nmap.width = %d\nmap.height = %d\n\n", data->map->width,
				data->map->height);
		data->map->map = data->check->map;
		i = 0;
		while (data->check->map[i])
			printf("%s\n", data->map->map[i++]);
	}
}

void	print_free(t_data *data)
{
	// print_textures(data);
	// print_map(data);
	print_player(data);
	// free_and_exit(data, "Program is runnin\n", 42);
}
