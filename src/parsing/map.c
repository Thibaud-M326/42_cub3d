/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:00:50 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/30 22:48:07 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

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

static char	*get_texture_path(char *line, t_data *data)
{
	int		i;
	char	*tmp;
	int		len;
	int		j;

	j = 0;
	len = (int)ft_strlen(line);
	i = 2;
	tmp = ft_calloc(len, sizeof(char));
	if (!tmp)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	while (line[i] && line[i] != '\n')
	{
		if ((line[i] >= '\t' && line[i] <= '\r') || line[i] == ' ')
			i++;
		else
		{
			tmp[j] = line[i];
			j++;
			i++;
		}
	}
	tmp[j] = '\0';
	printf("\npath = |%s|\n", tmp);
	return (tmp);
}

static void	check_identifier(char *line, t_data *data)
{
	int		i;
	t_check	*check;

	check = data->check;
	i = 0;
	while ((line[i] && line[i] >= '\t' && line[i] <= '\r') || line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] && line[i + 1] == 'O')
	{
		data->textures->path_n = get_texture_path(line, data);
		check->north = true;
	}
	else if (line[i] == 'S' && line[i + 1] && line[i + 1] == 'O')
	{
		data->textures->path_s = get_texture_path(line, data);
		check->south = true;
	}
	else if (line[i] == 'E' && line[i + 1] && line[i + 1] == 'A')
	{
		data->textures->path_e = get_texture_path(line, data);
		check->east = true;
	}
	else if (line[i] == 'W' && line[i + 1] && line[i + 1] == 'E')
	{
		data->textures->path_w = get_texture_path(line, data);
		check->west = true;
	}

	else if (line[i] == 'F')
		check->west = true;
	else if (line[i] == 'C')
		check->west = true;
	else if ((!check->north || !check->south || !check->east || !check->west
				|| !check->floor || !check->ceil) && (line[i] == '1'
				|| line[i] == '0' || line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'))
		data->check->is_map_valid = false;
	printf("%s\n", line);
}

static void	get_file_data(t_data *data)
{
	char	*line;
	int		rows;

	rows = 0;
	line = get_next_line(data->file->fd);
	while (line && data->check->is_map_valid)
	{
		check_identifier(line, data);
		free(line);
		rows++;
		line = get_next_line(data->file->fd);
	}
	if (line)
		free(line);
	if (rows < 9)
		free_and_exit(data, msg_predefined(INVALID_MAP), 0);
	if (!data->check->is_map_valid)
		free_and_exit(data, msg_predefined(INVALID_MAP), 0);
}

static int	open_file(t_data *data)
{
	int	fd;

	fd = open(data->file->map, O_RDONLY);
	if (fd < 0)
		free_and_exit(data, msg_predefined(MAP_NOT_FOUND), 0);
	return (fd);
}

void	check_map_file(char *input, t_data *data)
{
	char	*map_path;

	map_path = ft_strjoin("src/maps/", input);
	if (!map_path)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	data->file->map = ft_strdup(map_path);
	free(map_path);
	if (!data->file->map)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	data->file->fd = open_file(data);
	data->check = init_check_struct(data);
	data->textures = init_textures_struct(data);
	get_file_data(data);
	/* map ok */
	free_and_exit(data, msg_custom("Niceuuuu - map.c\n"), 0);
}
