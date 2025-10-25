/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:08:19 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/25 17:00:20 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"

static int	ft_atoi_rgb(const char *nptr, int *err)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			return (0);
		else if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(nptr[i]))
		*err = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	set_color(t_data *data, char id)
{
	int	r;
	int	g;
	int	b;
	int	err;

	err = 0;
	r = ft_atoi_rgb(data->check->color, &err);
	g = ft_atoi_rgb(ft_strchr(data->check->color, ',') + 1, &err);
	b = ft_atoi_rgb(ft_strrchr(data->check->color, ',') + 1, &err);
	if (err)
		free_and_exit(data, COLOR_FORMAT, 0);
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
