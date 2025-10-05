/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/05 21:33:47 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "mlx.h"

// int	main(void)
// {
// 	t_data	*data;

// 	data = init_data_struct();
// 	// parse_input(ac, av, data);
// 	if (!init_mlx(data))
// 		free_and_exit(data, msg_custom("init_mlx failed"), 1);
// 	render(data);
// 	deploy_mlx_hook(data);
// 	return (0);
// }

static void	print_textures(t_data *data)
{
	#include <stdio.h>
	printf("NORTH: %s\n", data->textures->path_n);
	printf("SOUTH: %s\n", data->textures->path_s);
	printf("WEST: %s\n", data->textures->path_w);
	printf("EAST: %s\n", data->textures->path_e);
	printf("FLOOR COLOR: %d\n", data->textures->floor_color);
	printf("CEIL COLOR: %d\n", data->textures->ceil_color);
	free_and_exit(data, msg_custom("Program is runnin\n"), 42);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data_struct();
	parse_input(ac, av, data);
	print_textures(data);
	// if (!init_mlx(data))
	// 	free_and_exit(data, msg_custom("init_mlx failed"), 1);
	// render(data);
	// deploy_mlx_hook(data);
	return (0);
}
