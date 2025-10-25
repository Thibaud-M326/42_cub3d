/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:07:53 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/23 23:21:51 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stddef.h>
#include "messages.h"

t_check	*init_check_struct(t_data *data)
{
	t_check	*check;

	check = ft_calloc(1, sizeof(t_check));
	if (!check)
		free_and_exit(data, MALLOC, 1);
	else
	{
		check->color = NULL;
		check->path = NULL;
		check->ext = NULL;
		check->map_str = NULL;
		check->map = NULL;
		check->width = 0;
		check->north = false;
		check->west = false;
		check->east = false;
		check->south = false;
		check->floor = false;
		check->ceil = false;
		check->are_identifiers_valid = false;
		check->got_nl = false;
		check->spawn = '\0';
	}
	return (check);
}

void	free_check(t_check *check)
{
	if (check)
	{
		if (check->color)
			free(check->color);
		if (check->path)
			free(check->path);
		if (check->ext)
			free(check->ext);
		if (check->map_str)
			free(check->map_str);
		if (check->map)
			free_strs(check->map);
		free(check);
	}
}
