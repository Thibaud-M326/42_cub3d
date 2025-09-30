/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/30 16:45:43 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube.h"
#include "libft.h"
#include "mlx.h"

int	main(void)
{
	t_mlx_data	mlx_data;
	t_mlx_img	mlx_img;

	if (!mlx_start(&mlx_data, &mlx_img))
		return (0);
	render(&mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
	return (0);
}
