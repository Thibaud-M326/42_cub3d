/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 21:39:33 by jmagand          ###   ########.fr       */
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
// 		free_and_exit(data, "init_mlx failed"), 1);
// 	render(data);
// 	deploy_mlx_hook(data);
// 	return (0);
// }

void	print_textures(t_data *data)
{
#include <stdio.h>
	printf("\nNORTH: %s\n", data->textures->path_n);
	printf("SOUTH: %s\n", data->textures->path_s);
	printf("WEST: %s\n", data->textures->path_w);
	printf("EAST: %s\n\n", data->textures->path_e);
	printf("FLOOR: %d\n", data->textures->floor_color);
	printf("CEIL: %d\n\n", data->textures->ceil_color);
	printf("MAP: %s\n\n", data->file->map);
}

static void	print(t_data *data)
{
	// print_textures(data);
	free_and_exit(data, "Program is runnin\n", 42);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data_struct();
	parse_input(ac, av, data);
	print(data);
	// if (!init_mlx(data))
	// 	free_and_exit(data, "init_mlx failed", 1);
	// render(data);
	// deploy_mlx_hook(data);
	return (0);
}
