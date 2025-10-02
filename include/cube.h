/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/02 20:44:32 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define USAGE_MSG "Usage: ./cub3D [FILE].cub"
# define AC_NBR_MSG "Need only one argument"
# define EMPTY_FILENAME_MSG "Filename is empty"
# define EMPTY_EXT_MSG "Extension is empty"
# define BAD_EXT_MSG "Extension is not '.cub'"
# define INVALID_MAP_MSG "Map file invalid"

# define BAD_CHAR_ID_MSG "Invalid character in file"
# define PLACE_MAP_MSG "Map content found before all identifiers were set"
# define MAP_NOT_FOUND_MSG "Map file not found"
# define DOUBLE_IDENTIFIER_MSG "There is a duplicated identifier"
# define INVALID_IDENTIFIER_MSG "Invalid identifier in file"

# define MALLOC_MSG "Malloc failed"

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
	BAD_CHAR_ID,
	INVALID_MAP,
	PLACE_MAP,
	MAP_NOT_FOUND,
	INVALID_IDENTIFIER,
	DOUBLE_IDENTIFIER,
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
	char		*line;
	char		*filename;
	char		*ext;
	char		*map;
	int			fd;
}				t_file;

typedef struct s_check
{
	char		*path;
	bool		north;
	bool		west;
	bool		east;
	bool		south;
	bool		floor;
	bool		ceil;
	bool		are_identifiers_valid;
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
	t_msg		*msg;
}				t_data;

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/
/* exit/free_exit */
void			free_and_exit_debug(t_data *data, t_msg msg, int err,
					const char *file, int line, const char *func);

# define free_and_exit(data, msg, err) \
	free_and_exit_debug(data, msg, err, __FILE__, __LINE__, __func__)

/* exit/handle_message */
char			*get_error_message(t_msg msg);
t_msg			msg_predefined(t_parse msg_type);
t_msg			msg_custom(char *custom_msg);

//src/hook/hook.c
int				deploy_mlx_hook(t_data *data);

/* parsing/input */
void			parse_input(int ac, char **av, t_data *data);

/* parsing/file_check */
void			check_error_in_file(t_data *data);
void			check_duplicate(t_data *data, char id);
void			check_identifier(t_data *data, char id);
void			check_path_file(char *input, t_data *data);

/* parsing/file_check_utils */
void			get_texture_path(t_data *data);
void			set_identifier(t_data *data, char id, char *path);

/* parsing/file */
void			check_file(char *input, t_data *data);

/* parsing/utils */
bool			are_all_identifiers_true(t_data *data);
bool			is_available_char_identifier(char c);
bool			is_available_char_map(char c);

//src/render/render.c
int				render(t_data *data);

//src/render/draw.c
void			put_one_pixel(t_data *data, int x, int y, int color);
int				mix_color(int red, int green, int blue);

/* structures/s_check */
t_check			*init_check_struct(t_data *data);
void			free_check(t_check *check);

/* structures/s_data */
t_data			*init_data_struct(void);

/* structures/s_file */
t_file			*init_file_struct(t_data *data);
void			free_file(t_file *file);

//structures/s_mlx
int				init_mlx(t_data *data);
int				free_mlx_data(t_mlx_data *mlx_data);

/* structures/s_msg */
t_msg			*init_msg_struct(t_data *data);

/* structures/s_textures */
t_textures		*init_textures_struct(t_data *data);
void			free_textures(t_textures *textures);

#endif