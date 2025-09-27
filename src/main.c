/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:32 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/27 22:45:20 by vscode           ###   ########.fr       */
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

	printf("Salut\n");
	if (!mlx_start(&mlx_data, &mlx_img))
		return (0);
	return (0);
}
