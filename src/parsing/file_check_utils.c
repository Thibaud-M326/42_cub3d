/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:52:00 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 22:29:10 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

char	*get_texture_path(t_data *data)
{
	int		i;
	char *tmp;
	size_t	len;
	int		j;

	j = 0;
	len = ft_strlen(data->file->line);
	i = 2;
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

void	set_identifier(t_data *data, char id, char *path)
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
