/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/28 19:43:50 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_exit.h"
#include "libft.h"
#include "parsing.h"
#include "render.h"
#include "structures.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (WIDTH < 100 || HEIGHT < 100)
	{
		ft_putendl_fd("Error:\nInvalid window size", 1);
		return (1);
	}
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
