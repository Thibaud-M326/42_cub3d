/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/27 23:43:40 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

static void	free_file(t_file *file)
{
	if (file)
	{
		if (file->ext)
			free(file->ext);
		if (file->filename)
			free(file->filename);
		if (file->map)
			free(file->map);
		if (file->fd > 0)
			close(file->fd); // TODO: check this
		free(file);
	}
}

static bool	check_map(char *input, t_file *file)
{
	char	*map;
	int		fd;

	map = ft_strjoin("src/maps/", input);
	if (!map)
		print_error(-4);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		free_file(file);
		print_error(-6);
	}
	if (file)
	{
		file->map = ft_strdup(map);
		if (!file->map)
		{
			free(map);
			free_file(file);
			print_error(-4);
		}
		file->fd = fd;
	}
	free(map);
	return (true);
}

int	main(int ac, char **av)
{
	t_file	*file;
	int		i;
	char	*dst;

	file = NULL;
	if (ac == 1)
		return (print_error(-1));
	if (ac != 2)
		return (print_error(-2));
	if (!check_input(av[1], &file))
		return (0);
	else
	{
		check_map(av[1], file);
		i = 150;
		while (i)
		{
			dst = get_next_line(file->fd);
			if (!dst)
			{
				free_file(file);
				printf("\n\nMAP COMPLETED\n");
				return (0);
			}
			printf("%s", dst);
			if (dst)
				free(dst);
			i--;
		}
		free_file(file);
	}
	return (0);
}
