/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:35:39 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 20:42:31 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	free_and_exit_debug(t_data *data, t_msg msg, int err, const char *file,
		int line, const char *func)
{
	ft_putendl_fd("Error:", STDERR_FILENO);
	ft_putendl_fd(get_error_message(msg), STDERR_FILENO);
	fprintf(stderr, "Exit in %s (%s:%d): \n", func, file, line);
	if (data)
	{
		if (data->file)
			free_file(data->file);
		if (data->check)
			free_check(data->check);
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
