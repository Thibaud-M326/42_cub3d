/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:06:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/28 23:26:46 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stddef.h>

t_file	*init_file_struct(char *filename, char *ext, t_file *file)
{
	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		print_error(-4);
	else
	{
		file->filename = filename;
		file->ext = ext;
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

void	free_and_exit(t_file *file, int err)
{
	free_file(file);
	if (err)
		exit(1);
	exit(0);
}