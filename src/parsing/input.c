/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:05:01 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/27 18:35:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"
#include "messages.h"

static void	get_filename(t_data *data, char *input, char *dot)
{
	data->file->filename = ft_strndup(input, dot - input);
	if (!data->file->filename && input[0] != '.')
		free_and_exit(data, MALLOC, 1);
	else if (!data->file->filename)
		free_and_exit(data, FILE_EMPTY_FILENAME, 0);
}

static void	check_input(char *input, t_data *data)
{
	char	*dot;

	data->file = init_file_struct(data);
	dot = ft_strrchr(input, '.');
	if (dot)
	{
		get_filename(data, input, dot);
		data->file->ext = ft_strdup(dot + 1);
		if (!data->file->ext)
			free_and_exit(data, FILE_EMPTY_EXT, 0);
		if (ft_strcmp(data->file->ext, "cub"))
			free_and_exit(data, FILE_WRONG_EXT, 0);
	}
	else
		free_and_exit(data, USAGE, 0);
}

void	parse_input(int ac, char **av, t_data *data)
{
	if (ac != 2)
	{
		if (ac <= 1)
			free_and_exit(data, USAGE, 0);
		else
			free_and_exit(data, AC_NBR, 0);
	}
	check_input(av[1], data);
}
