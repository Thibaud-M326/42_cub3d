/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:46:43 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 22:36:57 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "fcntl.h"
#include "libft.h"

void	open_xpm(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		free_and_exit(data, WRONG_PATH_TXT, 0);
	}
	else
		close(fd);
}

void	is_identifier_texture(t_data *data, char id, char *path)
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
}

void	check_duplicate(t_data *data, char id)
{
	t_check	*c;

	c = data->check;
	if ((id == 'N' && c->north) || (id == 'S' && c->south) ||
		(id == 'E' && c->east) || (id == 'W' && c->west))
		free_and_exit(data, ID_TXT_DOUBLE, 0);
	if ((id == 'F' && c->floor) || (id == 'C' && c->ceil))
		free_and_exit(data, ID_COLOR_DOUBLE, 0);
}

void	check_color_identifiers(t_data *data, int *i)
{
	if (data->file->line[*i] == 'F')
		check_identifier(data, 'F');
	else if (data->file->line[*i] == 'C')
		check_identifier(data, 'C');
}
