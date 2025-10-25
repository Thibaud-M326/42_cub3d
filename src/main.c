/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/25 17:51:54 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data_struct();
	parse_input(ac, av, data);
	check_file(av[1], data);
	is_map_valid(data);
	if (!init_mlx(data))
		free_and_exit(data, MLX_FAIL, 1);
	init_render(data);
	deploy_mlx_hook(data);
	return (0);
}
