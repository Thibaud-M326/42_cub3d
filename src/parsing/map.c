/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:56:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 00:02:22 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

// static void	clean(t_data *data)
// {
// 	(void)data;
// }

void	check_map(int i, t_data *data)
{
	if (is_available_char_map(data->file->line[i]))
	{
		if (are_all_identifiers_true(data))
			data->check->are_identifiers_valid = true;
		else
			free_and_exit(data, msg_predefined(PLACE_MAP), 0);
	}
	else
		free_and_exit(data, msg_predefined(INVALID_IDENTIFIER), 0);
}
