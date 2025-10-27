/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:48:09 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/27 18:35:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"
#include "parsing.h"
#include "messages.h"
#include <stdlib.h>

static void	get_map_gnl(t_data *data)
{
	int	err;

	err = 0;
	while (data->file->line)
	{
		check_map_line(data);
		free(data->file->line);
		data->file->line = get_next_line(data->file->fd, &err);
		if (err)
			free_and_exit(data, GNL, 1);
	}
	if (!data->check->spawn)
		free_and_exit(data, MAP_NO_SPAWN, 0);
	data->check->map = ft_split_set(data->check->map_str, "\n");
	if (!data->check->map)
		free_and_exit(data, MALLOC, 1);
}

static void	get_identifiers_gnl(t_data *data)
{
	int	err;

	err = 0;
	data->file->line = get_next_line(data->file->fd, &err);
	if (err)
	{
		free(data->file->line);
		free_and_exit(data, GNL, 1);
	}
	while (data->file->line && !data->check->are_identifiers_valid)
	{
		search_identifier(data);
		if (data->check->are_identifiers_valid)
			break ;
		free(data->file->line);
		data->file->line = get_next_line(data->file->fd, &err);
		if (err)
			free_and_exit(data, GNL, 1);
	}
	if (!are_all_identifiers_true(data))
		err_handler(data);
}

void	check_file(char *input, t_data *data)
{
	get_path_file(input, data);
	data->check = init_check_struct(data);
	data->textures = init_textures_struct(data);
	get_identifiers_gnl(data);
	get_map_gnl(data);
	data->map = init_map_struct(data);
	data->map->map = data->check->map;
	data->map->height = count_lines(data);
	data->map->width = data->check->width;
}
