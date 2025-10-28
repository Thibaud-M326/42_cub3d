/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_string_to_strings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:56:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/28 19:03:44 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_add_string_to_strings(char **strings, char *string)
{
	int		i;
	char	*new_str;

	if (!strings || !string)
		return (NULL);
	i = 0;
	while (strings[i])
	{
		new_str = ft_strjoin(strings[i], string);
		if (!new_str)
		{
			while (i-- > 0)
				free(strings[i]);
			free(strings);
			return (NULL);
		}
		free(strings[i]);
		strings[i] = new_str;
		i++;
	}
	return (strings);
}
