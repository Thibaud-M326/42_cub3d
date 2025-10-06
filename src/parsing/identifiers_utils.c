/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:46:43 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 19:01:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

void	check_duplicate(t_data *data, char id)
{
	t_check	*c;

	c = data->check;
	if ((id == 'N' && c->north) || (id == 'S' && c->south) ||
		(id == 'E' && c->east) || (id == 'W' && c->west))
		free_and_exit(data, ID_TXT_DOUBLE, 0);
	if ((id == 'F' && c->floor) || (id == 'C' && c->ceil))
		free_and_exit(data, ID_COLOR_DOUBLE, 0);
}

void	check_color_identifiers(t_data *data, int *i)
{
	if (data->file->line[*i] == 'F')
		check_identifier(data, 'F');
	else if (data->file->line[*i] == 'C')
		check_identifier(data, 'C');
}
