/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:48:07 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/25 17:46:59 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "libft.h"
#include <stdlib.h>

void	init_key_struct(t_data *data)
{
	t_key	*key;

	key = ft_calloc(1, sizeof(t_key));
	if (!key)
		free_and_exit(data, MALLOC, 1);
	data->key = key;
	return ;
}

void	free_key(t_key *key)
{
	free(key);
	return ;
}
