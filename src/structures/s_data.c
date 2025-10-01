/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:11 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/01 19:09:59 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stddef.h>

t_data	*init_data_struct(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		free_and_exit(data, msg_custom("Error:\nMalloc failed"), 1);
	data->file = NULL;
	data->textures = NULL;
	data->map = NULL;
	data->check = NULL;
	data->mlx_data = NULL;
	data->player = NULL;
	data->msg = init_msg_struct(data);
	return (data);
}

void	free_and_exit_debug(t_data *data, t_msg msg, int err, 
			const char *file, int line, const char *func)
{
	if (err)
	{
		fprintf(2, "Exit in %s (%s:%d): \n", func, file, line);
		ft_putendl_fd(get_error_message(msg), STDERR_FILENO);
	}	
	else
	{
		fprintf(1, "Exit in %s (%s:%d): \n", func, file, line);
		ft_putendl_fd(get_error_message(msg), STDOUT_FILENO);
	}
	if (data)
	{
		if (data->file)
			free_file(data->file);
		if (data->check)
			free(data->check);
		if (data->textures)
			free_textures(data->textures);
		if (data->mlx_data)
			free_mlx_data(data->mlx_data);
		if (data->msg)
			free(data->msg);
		free(data);
		if (err)
			exit(1);
	}
	exit(0);
}
