/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:00:50 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/29 22:07:30 by jmagand          ###   ########.fr       */
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

static void	get_file_data(t_data *data)
{
	char	*line;
	int		rows;

	rows = 0;
	line = get_next_line(data->file->fd);
	while (line)
	{
		// work with dest
        check_line(line);
		ft_putstr_fd(line, 1);
		free(line);
		rows++;
		line = get_next_line(data->file->fd);
	}
	if (rows < 9)
		free_and_exit(data, BAD_MAP, 1);
}

static int	open_file(t_data *data)
{
	int	fd;

	fd = open(data->file->map, O_RDONLY);
	if (fd < 0)
		free_and_exit(data, BAD_MAP, 2);
	return (fd);
}

void	check_map_file(char *input, t_data *data)
{
	char	*map_path;

	map_path = ft_strjoin("src/maps/", input);
	if (!map_path)
		free_and_exit(data, MALLOC, 1);
	data->file->map = ft_strdup(map_path);
	free(map_path);
	if (!data->file->map)
		free_and_exit(data, MALLOC, 1);
	data->file->fd = open_file(data);
    init_check_struct(data);
	get_file_data(data);
	/* map ok */
	free_and_exit(data, -1, 1);
	free_file(data->file);
}
