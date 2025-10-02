/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:48:50 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 01:57:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdlib.h>

void	check_error_in_file(char *line, t_data *data)
{
	if (line)
		free(line);
	if (!data->check->floor || !data->check->ceil || !data->check->north
		|| !data->check->south || !data->check->east || !data->check->west)
		data->check->are_identifiers_valid = false;
	if (!data->check->are_identifiers_valid)
		free_and_exit(data, msg_predefined(PLACE_MAP), 0);
}