/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:56:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 22:38:42 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

// static void	clean(t_data *data)
// {
// 	(void)data;
// }

// static int	atoi(t_data *data, char *str, int *idx)
// {
// 	int		nb;
// 	int		i;
// 	size_t	len;

// 	nb = 0;
// 	i = 0;
// 	while ((str[*idx] >= '\t' && str[*idx] <= '\r') || str[*idx] == ' ')
// 		(*idx)++;
// 	while (str[*idx] >= '0' && str[*idx] <= '9')
// 	{
// 		nb = nb * 10 + (str[*idx] - '0');
// 		(*idx)++;
// 	}
// 	return (nb);
// }

void	check_map_line(t_data *data)
{
	int		i;
	size_t	len;

	len = ft_strlen(data->file->line);
	i = 0;
	while (data->file->line[i + 1])
	{
		if (!is_available_char_map(data->file->line[i++]))
			free_and_exit(data, MAP_WRONG_CHAR, 0);
	}
}

void	check_map_order(int i, t_data *data)
{
	int	j;

	j = 0;
	if (is_available_char_map(data->file->line[i]))
	{
		if (are_all_identifiers_true(data))
			data->check->are_identifiers_valid = true;
		else
		{
			while (data->file->line[j] && data->file->line[j] != '\n')
			{
				if (!is_available_char_map(data->file->line[j++]))
					free_and_exit(data, ID_INVALID, 0);
			}
			free_and_exit(data, PLACE_MAP, 0);
		}
	}
	else
		free_and_exit(data, ID_INVALID, 0);
}
