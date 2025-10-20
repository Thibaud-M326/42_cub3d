/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:57:10 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/20 15:11:49 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>

typedef struct s_file
{
	char					*line;
	char					*filename;
	char					*ext;
	char					*map;
	int						fd;
}							t_file;

typedef struct s_check
{
	char					*color;
	char					*path;
	char					*ext;
	char					*map_str;
	char					**map;
	int						width;
	bool					north;
	bool					west;
	bool					east;
	bool					south;
	bool					floor;
	bool					ceil;
	bool					are_identifiers_valid;
	bool					got_nl;
	char					spawn;
}							t_check;

typedef struct s_map
{
	char					**map;
	int						height;
	int						width;
}							t_map;

typedef struct s_mlx_img	t_mlx_img;

typedef struct s_minimap
{
	int						start_col;
	int						start_row;
	int						cols;
	int						rows;
	int						player_rel_x;
	int						player_rel_y;
	t_mlx_img				*img;
	t_mlx_img				*img_borders;
}							t_minimap;

typedef struct s_textures
{
	int					floor_color;
	int					ceil_color;
	char				*path_n;
	char				*path_e;
	char				*path_w;
	char				*path_s;
	char				*extension;
	t_mlx_img			*tex_n;
	t_mlx_img			*tex_e;
	t_mlx_img			*tex_w;
	t_mlx_img			*tex_s;
	char				face;
	int					line_start;
	int					line_end;
}						t_textures;

typedef struct s_mlx_img
{
	void					*img_ptr;
	char					*img_data;
	int						width;
	int						height;
	int						bpp;
	int						size_line;
	int						endian;
}							t_mlx_img;

typedef struct s_mlx_data
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_mlx_img				*mlx_img;
	int						color;
}							t_mlx_data;

typedef struct s_ray
{
	double					dir_x;
	double					dir_y;
	double					length_x;
	double					length_y;
	double					unit_length_x;
	double					unit_length_y;
	double					map_check_x;
	double					map_check_y;
	int						step_x;
	int						step_y;
	int						side;
	double					distance;
	double					hit_pos_x;
	double					hit_pos_y;
}							t_ray;

typedef struct s_player
{
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					offset_pos_x;
	double					offset_pos_y;
	t_ray					ray;
	char					id;
}							t_player;

typedef struct s_key
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					left;
	int					right;
}	t_key;

typedef struct s_data		t_data;

typedef struct s_data
{
	t_file				*file;
	t_textures			*textures;
	t_map				*map;
	t_minimap			*minimap;
	t_check				*check;
	t_mlx_data			*mlx_data;
	t_player			*player;
	t_key				*key;
	int					(*render)(t_data *);
}						t_data;

/* structures/s_check.c */
t_check					*init_check_struct(t_data *data);
void					free_check(t_check *check);

/* structures/s_data.c */
t_data					*init_data_struct(void);

/* structures/s_file.c */
t_file					*init_file_struct(t_data *data);
void					free_file(t_file *file);

/* structures/s_key.c */
void					init_key_struct(t_data *data);
void					free_key(t_key *key);

/* structures/s_map.c */
t_map					*init_map_struct(t_data *data);

/* structures/minimap */
t_minimap				*init_minimap_struct(t_data *data);
void					free_minimap(t_data *data);

//structures/s_mlx.c
int						init_mlx(t_data *data);
int						free_mlx_data(t_mlx_data *mlx_data);

/* structures/s_player.c */
t_player				*init_player_struct(t_data *data);

/* structures/s_textures.c */
t_textures				*init_textures_struct(t_data *data);
void					free_textures(t_data *data, t_textures *textures);

#endif