/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:56:13 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/09 17:59:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/* GLOBAL */
# define GNL "A problem occured with GNL"
# define MALLOC "Malloc failed"

/* INPUT */
# define USAGE "Usage: ./cub3D [FILE].cub"
# define AC_NBR "Need only one argument"
# define FILE_EMPTY_FILENAME "Filename is empty"
# define FILE_EMPTY_EXT "Extension is empty"
# define FILE_WRONG_EXT "Extension is not '.cub'"
# define FILE_NOT_FOUND "File not found"

# define FILE_EMPTY_FILE "File: Empty file"

/* IDENTIFIERS */
# define ID_INVALID "Identifier: Invalid identifier found in file"
# define ID_TXT_DOUBLE "Identifier: There is a duplicate [NO, SO, EA, WE]"
# define ID_COLOR_DOUBLE "Identifier: There is a duplicate [F, C]"
# define ID_MISSING "Identifier: Atleast one identifier isn't set"

/* COLORS */
# define COLOR_FORMAT "Color: Format must be [0-255],[0-255],[0-255]"
# define COLOR_VALUE_RANGE "Color: Values must be between [0-255]"
# define COLOR_INVALID_CHAR "Color: Characters must be [0-9] ','"
# define COLOR_COMA "Color: Invalid coma number: \"R,G,B\""

/* TEXTURES */
# define MISSING_EXT_TXT "Texture: Missing extension \".xpm\""
# define WRONG_EXT_TXT "Texture: Extension is not \"xpm\""
# define MISSING_FILENAME_TXT "Texture: Missing filename \".xpm\""
# define WRONG_PATH_TXT "Texture: File not found"

/* MAP */
# define PLACE_MAP "Map: Content found before all identifiers were set"
# define MAP_WRONG_CHAR "Map: Invalid character found"
# define MAP_EMPTY_LINE "Map: Empty line found"
# define MAP_DOUBLE_SPAWN "Map: More than 1 spawn found"
# define MAP_NO_SPAWN "Map: No spawn found"
# define MAP_BORDER "Map: '0' not directly surrounded by '1'"
# define MAP_PLAYER "Map: Spawn is not closed"

#endif