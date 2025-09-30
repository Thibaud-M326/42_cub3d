/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:52:00 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/30 23:56:56 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

static void	check_duplicata(t_data *data, char id, char *line)
{
	if ((id == 'N' && data->check->north) || (id == 'S' && data->check->south)
		|| (id == 'E' && data->check->east) || (id == 'W' && data->check->west)
		|| (id == 'F' && data->check->floor) || (id == 'C'
			&& data->check->ceil))
	{
		free(line);
		free_and_exit(data, msg_predefined(DOUBLE_IDENTIFIER), 0);
	}
}

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
	{
		free(line);
		free_and_exit(data, msg_predefined(MALLOC), 1);
	}
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			i++;
		else
			tmp[j++] = line[i++];
	}
	tmp[j] = '\0';
	return (tmp);
}

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
	else if (id == 'F')
		data->check->floor = true;
	else if (id == 'C')
		data->check->ceil = true;
}

void	check_identifier(char *line, t_data *data, char id)
{
	t_check	*check;
	char	*path;

	check = data->check;
	check_duplicata(data, id, line);
	if (id == 'F' || id == 'C')
		path = NULL;
	else
		path = get_texture_path(line, data);
	set_identifier(data, id, path);
}