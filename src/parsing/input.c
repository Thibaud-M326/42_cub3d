/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:05:01 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/28 19:48:08 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "free_exit.h"
#include "structures.h"

static void	get_filename(t_data *data, char *input, char *dot)
{
	data->file->filename = ft_strndup(input, dot - input);
	if (!data->file->filename && input[0] != '.')
		free_and_exit(data, MALLOC, 1);
	else if (!data->file->filename)
		free_and_exit(data, FILE_EMPTY_FILENAME, 2);
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
			free_and_exit(data, FILE_EMPTY_EXT, 2);
		if (ft_strcmp(data->file->ext, "cub"))
			free_and_exit(data, FILE_WRONG_EXT, 2);
	}
	else
		free_and_exit(data, USAGE, 2);
}

void	parse_input(int ac, char **av, t_data *data)
{
	if (ac != 2)
	{
		if (ac <= 1)
			free_and_exit(data, USAGE, 2);
		else
			free_and_exit(data, AC_NBR, 2);
	}
	check_input(av[1], data);
}
