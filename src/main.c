/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/27 22:13:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_file	*file;
	int		fd;
	char	*map;
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
		i = 150;
		map = ft_strjoin("src/maps/", av[1]);
		if (!map)
			print_error(-4);
		fd = open(map, O_RDONLY);
		if (fd < 0)
		{
			free(map);
			if (file)
				free(file);
			print_error(-6);
			return (1);
		}
		file->map = map;
		free(map);
		while (i)
		{
			dst = get_next_line(fd);
			if (!dst)
			{
				if (file)
					free(file);
				return (0);
			}
			printf("%s", dst);
			if (dst)
				free(dst);
			i--;
		}
		printf("MAP COMPLETED\n");
		if (file)
			free(file);
	}
	return (0);
}
