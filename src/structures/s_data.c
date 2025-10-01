/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:11 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/01 18:37:21 by thmaitre         ###   ########.fr       */
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
		free_and_exit(data, MALLOC, 1);
	data->file = NULL;
	data->textures = NULL;
	data->map = NULL;
	data->check = NULL;
	data->mlx_data = NULL;
	data->player = NULL;
	return (data);
}

static char	*get_error_message(t_msg msg)
{
	static char	*messages[8];

	if (messages[USAGE] == NULL)
	{
		messages[USAGE] = USAGE_MSG;
		messages[AC_NBR] = AC_NBR_MSG;
		messages[EMPTY_FILENAME] = EMPTY_FILENAME_MSG;
		messages[EMPTY_EXT] = EMPTY_EXT_MSG;
		messages[MALLOC] = MALLOC_MSG;
		messages[BAD_EXT] = BAD_EXT_MSG;
		messages[INVALID_MAP] = INVALID_MAP_MSG;
		messages[MAP_NOT_FOUND] = MAP_NOT_FOUND_MSG;
	}
	if (msg >= USAGE && msg <= MAP_NOT_FOUND)
		return (messages[msg]);
	return ("Error:\nUnknown error");
}

void	free_and_exit_debug(t_data *data, t_msg msg, int err, 
			const char *file, int line, const char *func)
{
	fprintf(stderr, "Exit in %s (%s:%d): \n", func, file, line);
	ft_putendl_fd(get_error_message(msg), STDERR_FILENO);
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
		free(data);
		if (err)
			exit(1);
	}
	exit(0);
}