/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:05:01 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/27 23:43:50 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdbool.h>

bool	print_error(int err)
{
	if (err == -1)
		ft_putendl_fd("Usage: ./cub3D [FILE].cub", 1);
	else if (err == -2)
		ft_putendl_fd("Need only one argument", 1);
	else if (err == -3)
		ft_putendl_fd("Filename is empty", 1);
	else if (err == -4)
	{
		ft_putendl_fd("Malloc failed", 2);
		exit(1);
	}
	else if (err == -5)
		ft_putendl_fd("Extension is not '.cub'", 1);
	else if (err == -6)
	{
		ft_putendl_fd("File not found", 1);
		exit(1);
	}
	return (false);
}

static t_file	*init_file_struct(char *filename, char *ext, t_file *file)
{
	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		print_error(-4);
	else
	{
		file->filename = filename;
		file->ext = ext;
		file->map = NULL;
		file->fd = -1;
	}
	return (file);
}

static void	check_extension(char *file, char *ext)
{
	if (ft_strcmp(ext, "cub"))
	{
		if (file)
			free(file);
		if (ext)
			free(ext);
		print_error(-5);
		exit(0);
	}
}

static void	check_filename(char *filename)
{
	if (!filename)
	{
		print_error(-3);
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
			print_error(-4);
		check_filename(filename);
		ext = ft_strdup(dot + 1);
		if (!ext)
		{
			free(filename);
			print_error(-4);
		}
		check_extension(filename, ext);
	}
	else
		return (print_error(-1));
	*file = init_file_struct(filename, ext, *file);
	return (true);
}
