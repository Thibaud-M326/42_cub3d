/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:48:09 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/07 13:32:38 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <fcntl.h>

/*
◦ The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.

◦ The map must be closed/surrounded by walls, if not the program must return
an error.

◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.

◦ Except for the map content, each type of element can be separated by one or
more empty lines.

◦ Except for the map content which always has to be the last, each type of
element can be set in any order in the file.

◦ Except for the map, each type of information from an element can be separated
by one or more spaces. 


*/

// static void
// make && valgrind --leak-check=full --show-leak-kinds=all ./cub3D map1.cub

#include <stdio.h>

static void	get_map_gnl(t_data *data)
{
	int	err;

	// int	**map;
	err = 0;
	printf("%s", data->file->line);
	while (data->file->line)
	{
		check_map_line(data);
		free(data->file->line);
		data->file->line = get_next_line(data->file->fd, &err);
		printf("%s", data->file->line);
		if (err)
			free_and_exit(data, GNL, 1);
	}
}

static void	handle_error(t_data *data)
{
	t_check	*c;

	c = data->check;
	if (c->north || c->south || c->east || c->west || c->ceil || c->floor)
		free_and_exit(data, ID_MISSING, 0);
	else
		free_and_exit(data, FILE_EMPTY_FILE, 0);
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
		handle_error(data);
}

static void	get_path_file(char *input, t_data *data)
{
	t_file	*file;
	char	*map_path;

	file = data->file;
	/* invalid maps*/
	map_path = ft_strjoin("assets/maps/invalid_maps/", input);
	/* valid maps */
	// map_path = ft_strjoin("assets/maps/", input);
	if (!map_path)
		free_and_exit(data, MALLOC, 1);
	file->map = ft_strdup(map_path);
	free(map_path);
	if (!file->map)
		free_and_exit(data, MALLOC, 1);
	file->fd = open(file->map, O_RDONLY);
	if (file->fd < 0)
		free_and_exit(data, FILE_NOT_FOUND, 0);
}

void	check_file(char *input, t_data *data)
{
	get_path_file(input, data);
	data->check = init_check_struct(data);
	data->textures = init_textures_struct(data);
	get_identifiers_gnl(data);
	get_map_gnl(data);
	/* ALL identifiers ✅ */
}
