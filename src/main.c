/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/28 00:05:27 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdio.h>

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
