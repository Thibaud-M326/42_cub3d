/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/01 19:15:07 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>

int	main(void)
{
	t_data	*data;

	data = init_data_struct();
	// parse_input(ac, av, data);
	if (!init_mlx(data))
		free_and_exit(data, msg_custom("Error:\ninit_mlx failed"), 1);
	render(data);
	deploy_mlx_hook(data);
	return (0);
}
