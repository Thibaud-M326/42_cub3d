/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:45:14 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 23:05:11 by jmagand          ###   ########.fr       */
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
		free_and_exit(data, msg_custom("Empty texture filename"), 0);
	free(filename);
	return (texture_ext);
}

// static char	*check_color(t_data *data, int id)
// {
// 	int		count;
// 	int		i;
// 	char	*color;

// 	i = 0;
// 	count = 0;
// 	color = ft_calloc(1, sizeof(char));
// 	if (!color)
// 		return (NULL);
// 	if (id == 'C')
// 	{
// 		while (data->check->color)
// 		{
// 			if (data->check->color[i] == ',')
// 				count++;
// 			i++;
// 		}
// 		if (count != 3)
// 		{
// 			free_and_exit(data,
// 					msg_custom("Color format: [0-255],[0-255],[0-255]"), 0);
// 		}
// 	}
// 	return (color);
// }

#include <stdio.h>

static char	*get_color(t_data *data)
{
	int		i;
	char	*tmp;
	size_t	len;
	int		j;

	j = 0;
	len = ft_strlen(data->file->line);
	i = 1;
	tmp = ft_calloc(len, sizeof(char));
	if (!tmp)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	while (data->file->line[i] && data->file->line[i] != '\n')
	{
		if (ft_is_white_space(data->file->line[i]))
			i++;
		else
			tmp[j++] = data->file->line[i++];
	}
	tmp[j] = '\0';
	return (tmp);
}

void	check_identifier(t_data *data, char id)
{
	char	*res;

	res = NULL;
	check_duplicate(data, id);
	if (id == 'N' || id == 'S' || id == 'E' || id == 'W')
	{
		if (data->check->path)
			free(data->check->path);
		data->check->path = get_texture_path(data);
		res = check_texture_ext(data);
	}
	else if (id == 'F' || id == 'C')
	{
		if (data->check->color)
			free(data->check->color);
		data->check->color = get_color(data);
		// res = check_color(data, id);
	}
	set_identifier(data, id, res);
}
