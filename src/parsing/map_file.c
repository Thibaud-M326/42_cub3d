/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:37:37 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/01 21:39:20 by jmagand          ###   ########.fr       */
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

// static bool	is_map_available_char(char c)
// {
// 	printf("|%c|\n", c);
// 	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 		return (true);
// 	else
// 		ft_putendl_fd("Error\nInvalid char in map\n", STDOUT_FILENO);
// 	return (false);
// }

static void	is_an_identifier(char *line, int i, t_data *data)
{
	if (line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
			data->check->floor = true;
		else
			data->check->ceil = true;
	}
	else if (line[i] == 'N' && (line[i + 1]) && (line[i + 1]) == 'O')
		check_identifier(line, data, 'N');
	else if (line[i] == 'S' && (line[i + 1]) && (line[i + 1]) == 'O')
		check_identifier(line, data, 'S');
	else if (line[i] == 'E' && (line[i + 1]) && (line[i + 1]) == 'A')
		check_identifier(line, data, 'E');
	else if (line[i] == 'W' && (line[i + 1]) && (line[i + 1]) == 'E')
		check_identifier(line, data, 'W');
}

static void	search_identifier(char *line, t_data *data)
{
	int		i;
	t_check	*check;

	check = data->check;
	i = 0;
	while (ft_is_white_space(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C' || line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W' || line[i] == '\0')
	{
		printf("line[%d] = %c\n", i, line[i]);
		is_an_identifier(line, i, data);
	}
	else
	{
		free(line);
		free_and_exit(data, msg_predefined(BAD_CHAR_ID), 0);
	}
}

static void	get_file_data(t_data *data)
{
	char	*line;
	int		rows;

	rows = 0;
	line = get_next_line(data->file->fd);
	while (line && data->check->is_map_valid)
	{
		search_identifier(line, data);
		free(line);
		// printf("R = %d\n", rows);
		rows++;
		line = get_next_line(data->file->fd);
	}
	if (line)
		free(line);
	if (!data->check->floor || !data->check->ceil || !data->check->north
		|| !data->check->south || !data->check->east || !data->check->west)
		data->check->is_map_valid = false;
	if (rows < 9)
		free_and_exit(data, msg_predefined(NOT_ALL_DATA), 0);
	if (!data->check->is_map_valid)
	{
		printf("R = %d\n", rows);
		free_and_exit(data, msg_predefined(PLACE_MAP), 0);
	}
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
