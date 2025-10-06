/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:27:16 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 18:36:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

static void	set_identifier(t_data *data, char id, char *path)
{
	if (id == 'N')
	{
		data->textures->path_n = path;
		data->check->north = true;
	}
	else if (id == 'S')
	{
		data->textures->path_s = path;
		data->check->south = true;
	}
	else if (id == 'E')
	{
		data->textures->path_e = path;
		data->check->east = true;
	}
	else if (id == 'W')
	{
		data->textures->path_w = path;
		data->check->west = true;
	}
	set_color(data, id);
	if (id == 'F')
		data->check->floor = true;
	else if (id == 'C')
		data->check->ceil = true;
}

void	check_identifier(t_data *data, char id)
{
	char	*path;

	path = NULL;
	check_duplicate(data, id);
	if (id == 'N' || id == 'S' || id == 'E' || id == 'W')
	{
		path = get_texture_path(data);
		check_texture_ext(data, path);
	}
	else if (id == 'F' || id == 'C')
	{
		if (data->check->color)
			free(data->check->color);
		data->check->color = get_color(data);
		check_color_format(data);
		check_color_int(data);
	}
	set_identifier(data, id, path);
	if (are_all_identifiers_true(data))
		data->check->are_identifiers_valid = true;
}

void	search_identifier(t_data *data)
{
	int		i;
	t_file	*f;

	f = data->file;
	i = 0;
	while (ft_is_white_space(f->line[i]))
		i++;
	if (!f->line[i])
		return ;
	if (!is_available_char_identifier(f->line[i])
		&& data->check->are_identifiers_valid)
		if (is_available_char_map(f->line[i]))
			free_and_exit(data, PLACE_MAP, 0);
	if (f->line[i] == 'N' && (f->line[i + 1]) && (f->line[i + 1]) == 'O')
		check_identifier(data, 'N');
	else if (f->line[i] == 'S' && (f->line[i + 1]) && (f->line[i + 1]) == 'O')
		check_identifier(data, 'S');
	else if (f->line[i] == 'E' && (f->line[i + 1]) && (f->line[i + 1]) == 'A')
		check_identifier(data, 'E');
	else if (f->line[i] == 'W' && (f->line[i + 1]) && (f->line[i + 1]) == 'E')
		check_identifier(data, 'W');
	else if (f->line[i] == 'F' || f->line[i] == 'C')
		check_color_identifiers(data, &i);
	else
		check_map(i, data);
}
