/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/09 18:51:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include "mlx.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data_struct();
	parse_input(ac, av, data);
	check_file(av[1], data);
	is_map_valid(data);
	// print_free(data);
	if (!init_mlx(data))
		free_and_exit(data, MLX_FAIL, 1);
	render(data);
	deploy_mlx_hook(data);
	return (0);
}
