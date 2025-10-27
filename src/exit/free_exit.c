/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:35:39 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/27 15:49:09 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structures.h"
#include <stdlib.h>

void	free_and_exit_no_error(t_data *data)
{
	ft_putendl_fd("Exit: cub3D", STDOUT_FILENO);
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
	}
	exit(0);
}

void	free_and_exit(t_data *data, char *msg, int err)
{
	ft_putendl_fd("Error :", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
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
	}
	exit(err);
}
