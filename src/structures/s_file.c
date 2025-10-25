/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:06:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/25 17:38:51 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include <stdlib.h>

t_file	*init_file_struct(t_data *data)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		free_and_exit(data, MALLOC, 1);
	file->line = NULL;
	file->filename = NULL;
	file->ext = NULL;
	file->map = NULL;
	file->fd = -1;
	return (file);
}

void	free_file(t_file *file)
{
	if (file)
	{
		if (file->line)
			free(file->line);
		if (file->ext)
			free(file->ext);
		if (file->filename)
			free(file->filename);
		if (file->map)
			free(file->map);
		if (file->fd > 0)
			close(file->fd);
		free(file);
		file = NULL;
	}
}
