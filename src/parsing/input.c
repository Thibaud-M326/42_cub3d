/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:05:01 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/29 20:21:43 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdbool.h>

void	print_error(t_data *data, int err)
{
	if (err == -1 || err == -2 || err == -3 || err == -4)
	{
		if (err == -1)
			ft_putendl_fd("Usage: ./cub3D [FILE].cub", 1);
		else if (err == -2)
			ft_putendl_fd("Need only one argument", 1);
		else if (err == -3)
			ft_putendl_fd("Empty filename", 1);
		else if (err == -4)
			ft_putendl_fd("Empty extension", 1);
		free_and_exit(data, 0);
	}
	else if (err == -5)
		ft_putendl_fd("Error:\nMalloc failed", 2);
	free_and_exit(data, 1);
}

static char	*get_filename(t_data *data, char *input, char *dot)
{
	char	*filename;

	filename = ft_strndup(input, dot - input);
	if (!filename && input[0] != '.')
		print_error(data, -5);
	else if (!filename)
		print_error(data, -3);
	return (filename);
}

bool	check_input(char *input, t_data *data)
{
	char	*dot;

	data->file = init_file_struct(data);
	dot = ft_strrchr(input, '.');
	if (dot)
	{
		data->file->filename = get_filename(data, input, dot);
		data->file->ext = ft_strdup(dot + 1);
		if (!data->file->ext)
			print_error(data, -4);
		if (ft_strcmp(data->file->ext, "cub"))
		{
			ft_putendl_fd("Extension is not '.cub'", 1);
			free_and_exit(data, 0);
		}
	}
	else
		print_error(data, -1);
	return (true);
}
