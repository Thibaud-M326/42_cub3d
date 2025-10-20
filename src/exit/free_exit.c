/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:35:39 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/20 17:49:09 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "structures.h"
#include <stdio.h>
#include <unistd.h>

void	free_and_exit_debug(t_data *data, char *msg, int err, const char *file,
		int line, const char *func)
{
	ft_putendl_fd("Error :", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	fprintf(stderr, "Exit in %s (%s:%d): \n", func, file, line);
	if (data)
	{
		if (data->file)
			free_file(data->file);
		if (data->check)
			free_check(data->check);
		if (data->textures)
			free_textures(data, data->textures);
		if (data->minimap)
			free_minimap(data);
		if (data->mlx_data)
			free_mlx_data(data->mlx_data);
		if (data->player)
			free(data->player);
		if (data->map)
			free(data->map);
		if (data->key)
			free(data->key);
		if (data->fps)
			free_fps(data->fps);
		free(data);
		if (err)
			exit(1);
	}
	exit(0);
}
