/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:56:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/07 21:58:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

/*

◦ The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.

◦ The map must be closed/surrounded by walls, if not the program must return
an error.

◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.

*/

#include <stdio.h>

static bool	is_empty_line(t_data *data)
{
	int		i;
	t_file	*f;

	f = data->file;
	i = 0;
	while (f->line[i])
	{
		if (!ft_is_white_space(f->line[i++]))
			return (false);
	}
	return (true);
}

static char	*copy_line(t_data *data, int len)
{
	char	*map_str;
	char	*tmp;

	map_str = data->check->map_str;
	if (!map_str)
		tmp = ft_strdup(data->file->line);
	else
	{
		tmp = ft_strjoin(map_str, data->file->line);
		free(data->check->map_str);
	}
	if (!tmp)
		free_and_exit(data, MALLOC, 1);
	if (len > data->check->width)
		data->check->width = len;
	return (tmp);
}

void	check_map_line(t_data *data)
{
	int		i;
	int		len;
	t_file	*f;

	f = data->file;
	len = ft_strlen(f->line);
	i = 0;
	if (is_empty_line(data))
		data->check->got_nl = true;
	while (f->line[i])
	{
		if (!is_available_char_map(f->line[i]))
			free_and_exit(data, MAP_WRONG_CHAR, 0);
		else if (data->check->got_nl && is_available_char_map(f->line[i]))
			free_and_exit(data, MAP_EMPTY_LINE, 0);
		i++;
	}
	if (!is_empty_line(data))
		data->check->map_str = copy_line(data, len);
}

void	check_map_order(int i, t_data *data)
{
	int	j;

	j = 0;
	if (is_available_char_map(data->file->line[i]))
	{
		if (are_all_identifiers_true(data))
			data->check->are_identifiers_valid = true;
		else
		{
			while (data->file->line[j] && data->file->line[j] != '\n')
			{
				if (!is_available_char_map(data->file->line[j++]))
					free_and_exit(data, ID_INVALID, 0);
			}
			free_and_exit(data, PLACE_MAP, 0);
		}
	}
	else
		free_and_exit(data, ID_INVALID, 0);
}
