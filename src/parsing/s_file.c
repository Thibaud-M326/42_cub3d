/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:06:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/29 20:22:17 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stddef.h>

t_file	*init_file_struct(t_data *data)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		print_error(data, -4);
	else
	{
		file->filename = NULL;
		file->ext = NULL;
		file->map = NULL;
		file->fd = -1;
	}
	return (file);
}

void	free_file(t_file *file)
{
	if (file)
	{
		if (file->ext)
			free(file->ext);
		if (file->filename)
			free(file->filename);
		if (file->map)
			free(file->map);
		if (file->fd > 0)
			close(file->fd); // TODO: check if close need protect
		free(file);
	}
}
