/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:35:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/25 17:38:08 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include <stdlib.h>

static char	*trim_end(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (len > 0 && ft_is_white_space(str[len]))
	{
		str[len] = '\0';
		len--;
	}
	return (str);
}

void	check_texture_ext(t_data *data, char *path)
{
	int		i;
	char	*dot;

	i = 0;
	path = trim_end(path);
	dot = ft_strrchr(path, '.');
	if (!dot)
	{
		free(path);
		if (!dot)
			free_and_exit(data, MISSING_EXT_TXT, 0);
	}
	if (ft_strncmp(dot, ".xpm", 5))
	{
		free(path);
		free_and_exit(data, WRONG_EXT_TXT, 0);
	}
	if (ft_strlen(path) < 5)
	{
		free(path);
		free_and_exit(data, MISSING_FILENAME_TXT, 0);
	}
}

static int	trim_start(t_data *data, int i)
{
	while (data->file->line[i])
	{
		if (ft_is_white_space(data->file->line[i]))
			i++;
		else
			break ;
	}
	return (i);
}

char	*get_texture_path(t_data *data)
{
	int		i;
	char	*tmp;
	size_t	len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(data->file->line);
	i = trim_start(data, i);
	tmp = ft_calloc(len, sizeof(char));
	if (!tmp)
		free_and_exit(data, MALLOC, 1);
	i += 2;
	i = trim_start(data, i);
	while (i < (int)len && data->file->line[i + 1])
		tmp[j++] = data->file->line[i++];
	tmp[j] = '\0';
	return (tmp);
}
