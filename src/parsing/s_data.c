/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:11 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/30 00:11:00 by jmagand          ###   ########.fr       */
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

void	free_and_exit(t_data *data, t_msg msg, int err)
{
	ft_putendl_fd(get_error_message(msg), STDERR_FILENO);
	if (data)
	{
		if (data->file)
			free_file(data->file);
		if (data->check)
			free(data->check);
		if (data->textures)
			free_textures(data->textures);
		free(data);
		if (err)
			exit(1);
	}
	exit(0);
}