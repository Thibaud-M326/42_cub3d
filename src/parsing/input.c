/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:05:01 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/28 23:10:48 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdbool.h>

void	print_error(int err)
{
	if (err == -1 || err == -2 || err == -3)
	{
		if (err == -1)
			ft_putendl_fd("Usage: ./cub3D [FILE].cub", 1);
		else if (err == -2)
			ft_putendl_fd("Need only one argument", 1);
		else if (err == -3)
			ft_putendl_fd("Empty filename", 1);
		else if (err == -4)
			ft_putendl_fd("Empty extension", 1);
		exit(0);
	}
	else if (err == -5)
		ft_putendl_fd("Error:\nMalloc failed\n", 2);
	exit(1);
}

static void	check_extension(char *file, char *ext)
{
	if (ft_strcmp(ext, "cub"))
	{
		ft_putendl_fd("Extension is not '.cub'", 1);
		free(file);
		free(ext);
		exit(0);
	}
}

bool	check_input(char *input, t_file **file)
{
	char	*filename;
	char	*dot;
	char	*ext;

	dot = ft_strrchr(input, '.');
	if (dot)
	{
		filename = ft_strndup(input, dot - input);
		if (!filename && input[0] != '.')
			print_error(-5);
		else if (!filename)
			print_error(-3);
		ext = ft_strdup(dot + 1);
		if (!ext)
		{
			free(filename);
			print_error(-4);
		}
		check_extension(filename, ext);
	}
	else
		print_error(-1);
	*file = init_file_struct(filename, ext, *file);
	return (true);
}
