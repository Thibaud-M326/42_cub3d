/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/25 20:45:56 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

static bool	print_error(int err)
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
	return (false);
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

static bool	check_input(char *file)
{
	char	*filename;
	char	*dot;
	char	*ext;

	dot = ft_strrchr(file, '.');
	if (dot)
	{
		filename = ft_strndup(file, dot - file);
		if (!filename && file[0] != '.')
			return (print_error(-4));
		check_filename(filename);
		ext = ft_strdup(dot + 1);
		if (!ext)
		{
			free(filename);	
			return (print_error(-4));
		}
		check_extension(filename, ext);
	}
	else
		return (print_error(-1));
	return (true);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (print_error(-1));
	if (ac != 2)
		return (print_error(-2));
	if (!check_input(av[1]))
		return (0);
	else
	{
		printf("%s\n", av[1]);
		return (0);
	}
	return (0);
}