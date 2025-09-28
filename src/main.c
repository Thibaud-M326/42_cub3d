/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/28 23:24:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_file	*file;

	file = NULL;
	if (ac == 1)
		print_error(-1);
	if (ac != 2)
		print_error(-2);
	if (!check_input(av[1], &file))
		return (0);
	else
	{
		check_map_file(av[1], file);

	}
	return (0);
}
