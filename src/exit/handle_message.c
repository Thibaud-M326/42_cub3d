/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:39:06 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 17:35:57 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stddef.h>

char	*get_error_message(t_msg msg)
{
	static char	*messages[PARSE_MSG_COUNT];

	if (messages[USAGE] == NULL)
	{
		messages[USAGE] = USAGE_MSG;
		messages[AC_NBR] = AC_NBR_MSG;
		messages[EMPTY_FILENAME] = EMPTY_FILENAME_MSG;
		messages[EMPTY_EXT] = EMPTY_EXT_MSG;
		messages[MALLOC] = MALLOC_MSG;
		messages[BAD_EXT] = BAD_EXT_MSG;
		messages[BAD_CHAR_ID] = BAD_CHAR_ID_MSG;
		messages[INVALID_MAP] = INVALID_MAP_MSG;
		messages[PLACE_MAP] = PLACE_MAP_MSG;
		messages[MAP_NOT_FOUND] = MAP_NOT_FOUND_MSG;
		messages[INVALID_IDENTIFIER] = INVALID_IDENTIFIER_MSG;
		messages[DOUBLE_IDENTIFIER] = DOUBLE_IDENTIFIER_MSG;
	}
	if (msg.type == PREDEFINED && msg.u_type.predefined >= USAGE
		&& msg.u_type.predefined < PARSE_MSG_COUNT)
		return (messages[msg.u_type.predefined]);
	else if (msg.type == CUSTOM)
		return (msg.u_type.custom);
	return ("Error:\nUnknown error");
}

t_msg	msg_predefined(t_parse msg_type)
{
	t_msg	msg;

	msg.type = PREDEFINED;
	msg.u_type.predefined = msg_type;
	return (msg);
}

t_msg	msg_custom(char *custom_msg)
{
	t_msg   msg;

	msg.type = CUSTOM;
	msg.u_type.custom = custom_msg;
	return (msg);
}