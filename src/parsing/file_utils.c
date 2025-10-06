/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:56:45 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 18:34:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

void	check_error_in_file(t_data *data)
{
	if (!data->check->floor || !data->check->ceil || !data->check->north
		|| !data->check->south || !data->check->east || !data->check->west)
	{
		if (data->file->line)
			free(data->file->line);
		data->check->are_identifiers_valid = false;
		free_and_exit(data, PLACE_MAP, 0);
	}
}
