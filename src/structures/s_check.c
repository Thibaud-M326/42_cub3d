/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:07:53 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 22:09:33 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stddef.h>

t_check	*init_check_struct(t_data *data)
{
	t_check	*check;

	check = ft_calloc(1, sizeof(t_check));
	if (!check)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	else
	{
		check->color = NULL;
		check->path = NULL;
		check->north = false;
		check->west = false;
		check->east = false;
		check->south = false;
		check->floor = false;
		check->ceil = false;
		check->are_identifiers_valid = true;
	}
	return (check);
}

void	free_check(t_check *check)
{
	if (check)
	{
		if (check->path)
			free(check->path);
		if (check->color)
			free(check->color);
		free(check);
	}
}