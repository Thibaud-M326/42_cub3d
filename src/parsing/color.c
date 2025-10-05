/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:08:19 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/05 22:41:23 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

static int	ft_atoi_rgb(t_data *data, char *str, int *idx)
{
	int		nb;
	int		i;
	size_t	len;

	nb = 0;
	i = 0;
	len = ft_strlen(data->check->color);
	if (!len)
		free_and_exit(data,
			msg_custom("Color: Format must be [0-255],[0-255],[0-255]"), 0);
	while ((str[*idx] >= '\t' && str[*idx] <= '\r') || str[*idx] == ' ')
		(*idx)++;
	while (str[*idx] >= '0' && str[*idx] <= '9')
	{
		nb = nb * 10 + (str[*idx] - 48);
		(*idx)++;
	}
	if (nb < 0 || nb > 255)
		free_and_exit(data,
			msg_custom("Color: Value must be between [0-255]"), 0);
	return (nb);
}

void	check_color_int(t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	while (data->check->color[i])
	{
		if (ft_isdigit(data->check->color[i]))
		{
			nb = ft_atoi_rgb(data, data->check->color, &i);
			while (ft_isdigit(data->check->color[i]))
				i++;
		}
		else
			i++;
	}
}

void	check_color_format(t_data *data)
{
	int		count;
	int		i;
	char	*color;

	i = 0;
	count = 0;
	color = ft_calloc(1, sizeof(char));
	if (!color)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	while (data->check->color[i])
	{
		if (!ft_isdigit(data->check->color[i]) && data->check->color[i] != ',')
		{
			free(color);
			free_and_exit(data,
				msg_custom("Color: Characters must be [0-9] ','"), 0);
		}
		if (data->check->color[i] == ',')
			count++;
		i++;
	}
	free(color);
	if (count != 2)
		free_and_exit(data, msg_custom("Color: Invalid coma number [R,G,B]"),
			0);
}

char	*get_color(t_data *data)
{
	int		i;
	char	*tmp;
	size_t	len;
	int		j;

	j = 0;
	len = ft_strlen(data->file->line);
	i = 1;
	tmp = ft_calloc(len, sizeof(char));
	if (!tmp)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	while (data->file->line[i])
	{
		if (ft_is_white_space(data->file->line[i]))
			i++;
		else
			tmp[j++] = data->file->line[i++];
	}
	tmp[j] = '\0';
	return (tmp);
}
