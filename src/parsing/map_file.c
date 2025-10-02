/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:37:37 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 02:04:55 by jmagand          ###   ########.fr       */
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

◦ If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice. 

*/

/* 

◦ Except for the map content, each type of element can be separated by one or
more empty lines.

◦ Except for the map content which always has to be the last, each type of
element can be set in any order in the file.

◦ Except for the map, each type of information from an element can be separated
by one or more spaces. 

◦ Except for the map, each element must begin with its type identifier (composed
by one or two characters),
followed by its specific information in a strict order:

∗ North texture:
NO ./path_to_the_north_texture
· identifier: NO
· path to the north texture

∗ South texture:
SO ./path_to_the_south_texture
· identifier: SO
· path to the south texture

∗ West texture:
WE ./path_to_the_west_texture
· identifier: WE
· path to the west texture

∗ East texture:
EA ./path_to_the_east_texture
· identifier: EA
· path to the east texture

∗ Floor color:
F 220,100,0
· identifier: F
· R,G,B colors in range [0,255]: 0, 255, 255

∗ Ceiling color:
C 225,30,0
· identifier: C
· R,G,B colors in range [0,255]: 0, 255, 255

*/

// static void
// make && valgrind --leak-check=full --show-leak-kinds=all ./cub3D map1.cub

#include <stdio.h>

static void	check_map(char *line, char c, t_data *data)
{
	if (is_available_char_map(c))
	{
		if (are_all_identifiers_true(data))
			data->check->are_identifiers_valid = true;
		else
		{
			free(line);
			free_and_exit(data, msg_predefined(PLACE_MAP), 0);
		}
	}
	else
	{
		free(line);
		free_and_exit(data, msg_predefined(BAD_CHAR_ID), 0);
	}
}

static bool	is_valid_identifier(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'F' || c == 'C');
}

static void	search_identifier(char *line, t_data *data)
{
	int		i;
	t_check	*check;

	check = data->check;
	i = 0;
	while (ft_is_white_space(line[i]))
		i++;
	if (!line[i])
		return ;
	if (!is_valid_identifier(line[i]) && !check->are_identifiers_valid)
	{
		if (is_available_char_map(line[i]))
		{
			free(line);
			free_and_exit(data, msg_predefined(PLACE_MAP), 0);
		}
	}
	if (line[i] == 'N' && (line[i + 1]) && (line[i + 1]) == 'O')
		check_identifier(line, data, 'N');
	else if (line[i] == 'S' && (line[i + 1]) && (line[i + 1]) == 'O')
		check_identifier(line, data, 'S');
	else if (line[i] == 'E' && (line[i + 1]) && (line[i + 1]) == 'A')
		check_identifier(line, data, 'E');
	else if (line[i] == 'W' && (line[i + 1]) && (line[i + 1]) == 'E')
		check_identifier(line, data, 'W');
	else if (line[i] == 'F')
		check->floor = true;
	else if (line[i] == 'C')
		check->ceil = true;
	else
		check_map(line, line[i], data);
}

static void	get_file_data(t_data *data)
{
	char	*line;
	int		err;

	err = 0;
	line = get_next_line(data->file->fd, &err);
	if (err)
	{
		free(line);
		free_and_exit(data, msg_custom("Gnl failed"), 1);
	}
	while (line && data->check->are_identifiers_valid)
	{
		printf("%s\n", line);
		search_identifier(line, data);
		free(line);
		line = get_next_line(data->file->fd, &err);
		if (err)
		{
			free(line);
			free_and_exit(data, msg_custom("Gnl failed"), 1);
		}
	}
	check_error_in_file(line, data);
}

void	check_map_file(char *input, t_data *data)
{
	char	*map_path;
	t_file	*file;

	file = data->file;
	map_path = ft_strjoin("src/maps/", input);
	if (!map_path)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	file->map = ft_strdup(map_path);
	free(map_path);
	if (!file->map)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	file->fd = open(file->map, O_RDONLY);
	if (file->fd < 0)
		free_and_exit(data, msg_predefined(MAP_NOT_FOUND), 0);
	data->check = init_check_struct(data);
	data->textures = init_textures_struct(data);
	get_file_data(data);
	/* map ok */
	free_and_exit(data, msg_custom("Niceuuuu - map_file.c\n"), 0);
}
