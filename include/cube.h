/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/30 22:58:14 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define USAGE_MSG "Error:\nUsage: ./cub3D [FILE].cub"
# define AC_NBR_MSG "Error:\nNeed only one argument"
# define EMPTY_FILENAME_MSG "Error:\nFilename is empty"
# define EMPTY_EXT_MSG "Error:\nExtension is empty"
# define BAD_EXT_MSG "Error:\nExtension is not '.cub'"
# define MAP_NOT_FOUND_MSG "Error:\nMap file not found"
# define INVALID_MAP_MSG "Error:\nMap file invalid"

# define MALLOC_MSG "Error:\nMalloc failed"

/****************************************************************************/
/*                                INCLUDE									*/
/****************************************************************************/
# include <stdbool.h>

/****************************************************************************/
/*                                ENUM										*/
/****************************************************************************/
typedef enum e_msg_type
{
	PREDEFINED,
	CUSTOM,
}				t_msg_type;

typedef enum e_parse
{
	USAGE,
	AC_NBR,
	EMPTY_FILENAME,
	EMPTY_EXT,
	MALLOC,
	BAD_EXT,
	INVALID_MAP,
	MAP_NOT_FOUND,
	PARSE_MSG_COUNT,
}				t_parse;

typedef struct s_msg
{
	t_msg_type	type;
	union
	{
		t_parse	predefined;
		char	*custom;
	} u_type;
}				t_msg;

/****************************************************************************/
/*                                STRUCT									*/
/****************************************************************************/
typedef struct s_file
{
	char		*filename;
	char		*ext;
	char		*map;
	int			fd;
}				t_file;

typedef struct s_check
{
	bool		north;
	bool		west;
	bool		east;
	bool		south;
	bool		floor;
	bool		ceil;
	bool		is_map_valid;
}				t_check;

typedef struct s_map
{
	char		**map;
	int			map_h;
	int			map_w;
}				t_map;

typedef struct s_textures
{
	int			floor_color;
	int			ceil_color;
	char		*path_n;
	char		*path_e;
	char		*path_w;
	char		*path_s;
}				t_textures;

typedef struct s_mlx_img
{
	void		*img_ptr;
	char		*img_data;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	*mlx_img;
	int			color;
}				t_mlx_data;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
}				t_player;

typedef struct s_hook_args
{
	t_player	*player;
}				t_hook_args;

typedef struct s_data
{
	t_file		*file;
	t_textures	*textures;
	t_map		*map;
	t_check		*check;
	t_mlx_data	*mlx_data;
	t_player	*player;
	t_hook_args	*hook_args;
	t_msg		*msg;
}				t_data;

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/
/* input */
void			parse_input(int ac, char **av, t_data *data);

/* s_file */
t_file			*init_file_struct(t_data *data);
void			free_file(t_file *file);

/* s_data */
t_data			*init_data_struct(void);
void			free_and_exit(t_data *data, t_msg msg, int err);

/* s_check */
t_check			*init_check_struct(t_data *data);

/* s_textures */
t_textures		*init_textures_struct(t_data *data);
void			free_textures(t_textures *textures);

/* s_msg */
t_msg			*init_msg_struct(t_data *data);

/* map */
void			check_map_file(char *input, t_data *data);

//structures/s_mlx
int				mlx_start(t_data *data);

//src/render/render.c
int				render(t_data *data);

//src/render/draw.c
void			put_one_pixel(t_data *data, int x, int y, int color);
int				mix_color(int red, int green, int blue);

/* messages */
char			*get_error_message(t_msg msg);
t_msg			msg_predefined(t_parse msg_type);
t_msg			msg_custom(char *custom_msg);

#endif