/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:01:53 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/08 17:57:02 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdbool.h>

void	is_spawn(t_data *data, char c)
{
	if (data->check->spawn && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		free_and_exit(data, MAP_DOUBLE_SPAWN, 0);
	else
	{
		if (c == 'N')
			data->check->spawn = 'N';
		else if (c == 'S')
			data->check->spawn = 'S';
		else if (c == 'E')
			data->check->spawn = 'E';
		else if (c == 'W')
			data->check->spawn = 'W';
	}
}

bool	are_all_identifiers_true(t_data *data)
{
	t_check	*check;

	check = data->check;
	return (check->north && check->south && check->east && check->west
		&& check->floor && check->ceil);
}

bool	is_available_char_identifier(char c)
{
	return (c == 'F' || c == 'C' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '\0');
}

bool	is_available_char_map(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}
