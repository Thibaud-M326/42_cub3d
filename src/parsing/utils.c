/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:01:53 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 01:34:32 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdbool.h>

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
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}