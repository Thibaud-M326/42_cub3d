/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/07 19:06:23 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

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
# define COLOR_COMA "Color: Invalid coma number: \"R,G,B"

/* TEXTURES */
# define MISSING_EXT_TXT "Texture: Missing extension \".xpm"
# define WRONG_EXT_TXT "Texture: Extension is not \"xpm"
# define MISSING_FILENAME_TXT "Texture: Missing filename \"\".xpm"
# define WRONG_PATH_TXT "Texture: File not found"

/* MAP */
# define PLACE_MAP "Map: Content found before all identifiers were set"
# define MAP_WRONG_CHAR "Map: Invalid character found"
# define MAP_EMPTY_LINE "Map: Empty line found"

/****************************************************************************/
/*                                INCLUDE									*/
/****************************************************************************/
# include <stdbool.h>

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
	char		*color;
	char		*path;
	char		*ext;
	char		*map_str;
	char		**map;
	int			width;
	bool		north;
	bool		west;
	bool		east;
	bool		south;
	bool		floor;
	bool		ceil;
	bool		are_identifiers_valid;
	bool		got_nl;
}				t_check;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
}				t_map;

typedef struct s_textures
{
	int			floor_color;
	int			ceil_color;
	char		*path_n;
	char		*path_e;
	char		*path_w;
	char		*path_s;
	char		*extension;
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
}				t_data;

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/
/* exit/utils */
void			free_strs(char **strs);

/* exit/free_exit */
void			free_and_exit_debug(t_data *data, char *msg, int err,
					const char *file, int line, const char *func);

# define free_and_exit(data, msg, err) \
	free_and_exit_debug(data, msg, err, __FILE__, __LINE__, __func__)

//src/hook/hook.c
int				deploy_mlx_hook(t_data *data);

/* parsing/color */
void			set_color(t_data *data, char id);
void			check_color_int(t_data *data);
void			check_color_format(t_data *data);
char			*get_color(t_data *data);

/* parsing/file_utils */
int				count_lines(t_data *data);
void			err_handler(t_data *data);
void			get_path_file(char *input, t_data *data);

/* parsing/file */
void			check_file(char *input, t_data *data);

/* parsing/flood_fill */
void			flood_fill(t_data *data);

/* parsing/identifiers_utils */
void			open_xpm(t_data *data, char *path);
void			is_identifier_texture(t_data *data, char id, char *path);
void			check_duplicate(t_data *data, char id);
void			check_color_identifiers(t_data *data, int *i);

/* parsing/identifiers */
void			check_identifier(t_data *data, char id);
void			search_identifier(t_data *data);

/* parsing/input */
void			parse_input(int ac, char **av, t_data *data);

/* parsing/map */
void			check_map_line(t_data *data);
void			check_map_order(int i, t_data *data);

/* parsing/textures */
void			check_texture_ext(t_data *data, char *path);
char			*get_texture_path(t_data *data);

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

/* structures/s_map */
t_map			*init_map_struct(t_data *data);
void			free_map(t_map *map);

//structures/s_mlx
int				init_mlx(t_data *data);
int				free_mlx_data(t_mlx_data *mlx_data);

/* structures/s_textures */
t_textures		*init_textures_struct(t_data *data);
void			free_textures(t_textures *textures);

#endif