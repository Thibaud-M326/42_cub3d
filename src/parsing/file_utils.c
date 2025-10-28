/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:01:24 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/28 19:46:53 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "libft.h"
#include "free_exit.h"
#include <fcntl.h>

int	count_lines(t_data *data)
{
	int	rows;

	rows = 0;
	while (data->map->map[rows])
		rows++;
	return (rows);
}

void	err_handler(t_data *data)
{
	t_check	*c;

	c = data->check;
	if (c->north || c->south || c->east || c->west || c->ceil || c->floor)
		free_and_exit(data, ID_MISSING, 2);
	else
		free_and_exit(data, FILE_EMPTY_FILE, 2);
}

void	get_path_file(char *input, t_data *data)
{
	t_file	*file;
	char	*map_path;

	file = data->file;
	map_path = input;
	file->map = ft_strdup(map_path);
	if (!file->map)
		free_and_exit(data, MALLOC, 1);
	file->fd = open(file->map, O_RDONLY);
	if (file->fd < 0)
		free_and_exit(data, FILE_NOT_FOUND, 2);
}
