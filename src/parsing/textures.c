/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:35:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/05 22:38:28 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

void	check_texture_ext(t_data *data, char *path)
{
	int		i;
	char	*dot;

	i = 0;
	dot = ft_strrchr(path, '.');
	if (!dot)
	{
		free(path);
		if (!dot)
			free_and_exit(data, msg_custom("Texture extension is missing"), 0);
	}
	while (dot[i])
	{
		if (dot[i] != ".xpm"[i])
		{
			free(path);
			free_and_exit(data, msg_custom("Texture extension is not .xpm"), 0);
		}
		i++;
	}
	if (ft_strlen(path) < 5)
	{
		free(path);
		free_and_exit(data, msg_custom("Texture: Missing filename .xpm"), 0);
	}
}

char	*get_texture_path(t_data *data)
{
	int		i;
	char	*tmp;
	size_t	len;
	int		j;

	j = 0;
	len = ft_strlen(data->file->line);
	i = 2;
	tmp = ft_calloc(len, sizeof(char));
	if (!tmp)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	while (data->file->line[i])
	{
		if (ft_is_white_space(data->file->line[i]))
			i++;
		else
			tmp[j++] = data->file->line[i++];
	}
	tmp[j] = '\0';
	return (tmp);
}
