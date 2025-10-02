/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_msg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:26:13 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 01:12:33 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

t_msg	*init_msg_struct(t_data *data)
{
	t_msg	*msg;

	msg = ft_calloc(1, sizeof(t_msg));
	if (!msg)
		free_and_exit(data, msg_custom("Malloc failed"), 1);
	return (msg);
}