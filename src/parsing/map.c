/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:00:50 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/29 20:04:23 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

/*

Your program must take as a first argument a scene description file with the .cub
extension.

◦ The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.

◦ The map must be closed/surrounded by walls, if not the program must return
an error.

◦ Except for the map content, each type of element can be separated by one or
more empty lines.

◦ Except for the map content which always has to be the last, each type of
element can be set in any order in the file.

◦ Except for the map, each type of information from an element can be separated
by one or more spaces.

◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.

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

◦ If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice. 

*/

static void	get_map(t_data *data)
{
	char	*dst;
	int		rows;

	rows = 0;
	dst = get_next_line(data->file->fd);
	while (dst)
	{
		ft_putstr_fd(dst, 1);
		free(dst);
		rows++;
		dst = get_next_line(data->file->fd);
	}
	if (rows < 9)
	{
		ft_putendl_fd("Error:\nInvalid map", 2);
		free_and_exit(data, 1);
	}
}

static int	open_map(t_data *data)
{
	int	fd;

	fd = open(data->file->map, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error:", 2);
		ft_putstr_fd(data->file->filename, 2);
		ft_putendl_fd(".cub not found", 2);
		free_and_exit(data, 1);
	}
	return (fd);
}

void	check_map_file(char *input, t_data *data)
{
	char	*map_path;

	map_path = ft_strjoin("src/maps/", input);
	if (!map_path)
	{
		ft_putendl_fd("Error:\nMalloc failed\n", 2);
		free_and_exit(data, 1);
	}
	data->file->map = ft_strdup(map_path);
	free(map_path);
	if (!data->file->map)
	{
		ft_putendl_fd("Error:\nMalloc failed", 2);
		free_and_exit(data, 1);
	}
	data->file->fd = open_map(data);
	get_map(data);
	/* map ok */
    free_and_exit(data, 1);
	free_file(data->file);
}
