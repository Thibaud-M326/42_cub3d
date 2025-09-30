/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:42:44 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/27 19:50:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_b_zero(void *s)
{
	unsigned char	*temp_s;
	size_t			i;

	temp_s = (unsigned char *)s;
	i = 0;
	while (temp_s[i])
	{
		temp_s[i] = 0;
		i++;
	}
}

static char	*handle_eof(char *line, char *buffer, ssize_t read_bytes)
{
	if (line[0] == '\0' || read_bytes == -1)
	{
		free(line);
		ft_b_zero(buffer);
		return (NULL);
	}
	return (line);
}

static ssize_t	set_line(char *buffer, char **line)
{
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	*line = ft_strjoin_gnl(*line, buffer, i);
	if (!*line)
		return (-1);
	if (buffer[i - 1] == '\n')
	{
		ft_memmove_gnl(buffer, buffer + i, ft_strlen(buffer + i) + 1);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX + 1][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_bytes;

	line = NULL;
	if (fd > FD_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (1)
	{
		if (!buffer[fd][0])
		{
			read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (read_bytes <= 0)
				return (handle_eof(line, buffer[fd], read_bytes));
			buffer[fd][read_bytes] = '\0';
		}
		if (set_line(buffer[fd], &line))
			return (line);
		ft_b_zero(buffer[fd]);
	}
}
