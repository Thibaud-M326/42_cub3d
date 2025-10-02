/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:45:14 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 20:53:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

void	check_error_in_file(t_data *data)
{
	if (data->file->line)
		free(data->file->line);
	if (!data->check->floor || !data->check->ceil || !data->check->north
		|| !data->check->south || !data->check->east || !data->check->west)
		data->check->are_identifiers_valid = false;
	if (!data->check->are_identifiers_valid)
		free_and_exit(data, msg_predefined(PLACE_MAP), 0);
}

void	check_duplicate(t_data *data, char id)
{
	if ((id == 'N' && data->check->north) || (id == 'S' && data->check->south)
		|| (id == 'E' && data->check->east) || (id == 'W' && data->check->west)
		|| (id == 'F' && data->check->floor) || (id == 'C'
			&& data->check->ceil))
		free_and_exit(data, msg_predefined(DOUBLE_IDENTIFIER), 0);
}

void	check_path_file(char *input, t_data *data)
{
	t_file	*file;
	char	*map_path;

	file = data->file;
	/* invalid maps*/
	map_path = ft_strjoin("assets/maps/invalid_maps/", input);
	/* valid maps */
	// map_path = ft_strjoin("assets/maps/", input);
	if (!map_path)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	file->map = ft_strdup(map_path);
	free(map_path);
	if (!file->map)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	file->fd = open(file->map, O_RDONLY);
	if (file->fd < 0)
		free_and_exit(data, msg_predefined(MAP_NOT_FOUND), 0);
}

static char	*get_texture_filename(t_data *data, char *dot)
{
	char	*filename;

	filename = ft_strndup(data->file->line, dot - data->file->line);
	if (!filename && data->file->line[0] != '.')
		free_and_exit(data, msg_predefined(MALLOC), 1);
	else if (!filename)
		free_and_exit(data, msg_custom("Empty filename .xpm"), 0);
	return (filename);
}

static char	*check_texture_ext(t_data *data)
{
	char	*dot;
	char	*texture_ext;
	char	*filename;

	texture_ext = NULL;
	filename = NULL;
	dot = ft_strrchr(data->check->path + 1, '.');
	if (dot)
	{
		filename = get_texture_filename(data, dot);
		texture_ext = ft_strdup(dot + 1);
		if (ft_strcmp(texture_ext, "xpm"))
		{
			free(filename);
			free(texture_ext);
			free_and_exit(data, msg_custom("Texture extension is not .xpm"), 0);
		}
	}
	else
		free_and_exit(data, msg_custom("Empty texture extension"), 0);
	free(filename);
	return (texture_ext);
}

void	check_identifier(t_data *data, char id)
{
	char *res;

	res = NULL;
	check_duplicate(data, id);
	if (id == 'N' || id == 'S' || id == 'E' || id == 'W')
	{
		get_texture_path(data);
		res = check_texture_ext(data);
		if (data->check->path)
			free(data->check->path);
	}
	set_identifier(data, id, res);
}