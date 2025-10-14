/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:08:19 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/14 18:42:21 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"

void	set_color(t_data *data, char id)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(data->check->color);
	g = ft_atoi(ft_strchr(data->check->color, ',') + 1);
	b = ft_atoi(ft_strrchr(data->check->color, ',') + 1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		free_and_exit(data, COLOR_VALUE_RANGE, 0);
	if (id == 'F')
		data->textures->floor_color = mix_color(r, g, b);
	else
		data->textures->ceil_color = mix_color(r, g, b);
}

static int	parse_color_number(char *s, int *i)
{
	int	digit_count;

	digit_count = 0;
	while (ft_is_white_space(s[*i]))
		(*i)++;
	while (ft_isdigit(s[*i]))
	{
		digit_count++;
		(*i)++;
	}
	if (digit_count == 0 || digit_count > 3)
		return (0);
	while (ft_is_white_space(s[*i]))
		(*i)++;
	return (1);
}

void	check_color_format(t_data *data)
{
	int		i;
	int		count;
	char	*s;

	i = 0;
	count = 0;
	s = data->check->color;
	while (s[i])
	{
		if (!parse_color_number(s, &i))
			free_and_exit(data, COLOR_FORMAT, 0);
		if (s[i] == ',')
		{
			count++;
			i++;
		}
		else if (s[i] && !ft_is_white_space(s[i]))
			free_and_exit(data, COLOR_FORMAT, 0);
	}
	if (count != 2)
		free_and_exit(data, COLOR_COMA, 0);
}

char	*get_color(t_data *data)
{
	int		i;
	char	*tmp;
	size_t	len;
	int		j;

	j = 0;
	len = ft_strlen(data->file->line);
	i = 0;
	while (ft_is_white_space(data->file->line[i]))
		i++;
	tmp = ft_calloc(len, sizeof(char));
	if (!tmp)
		free_and_exit(data, MALLOC, 1);
	i += 1;
	while (ft_is_white_space(data->file->line[i]))
		i++;
	while (data->file->line[i + 1])
		tmp[j++] = data->file->line[i++];
	tmp[j] = '\0';
	return (tmp);
}
