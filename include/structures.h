/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:57:10 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/09 19:04:24 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>

typedef struct s_file
{
	char				*line;
	char				*filename;
	char				*ext;
	char				*map;
	int					fd;
}						t_file;

typedef struct s_check
{
	char				*color;
	char				*path;
	char				*ext;
	char				*map_str;
	char				**map;
	int					width;
	bool				north;
	bool				west;
	bool				east;
	bool				south;
	bool				floor;
	bool				ceil;
	bool				are_identifiers_valid;
	bool				got_nl;
	char				spawn;
}						t_check;

typedef struct s_map
{
	char				**map;
	int					height;
	int					width;
}						t_map;

typedef struct s_textures
{
	int					floor_color;
	int					ceil_color;
	char				*path_n;
	char				*path_e;
	char				*path_w;
	char				*path_s;
	char				*extension;
}						t_textures;

typedef struct s_mlx_img
{
	void				*img_ptr;
	char				*img_data;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_mlx_img;

typedef struct s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_mlx_img			*mlx_img;
	int					color;
}						t_mlx_data;

typedef struct s_ray
{
	double				dir_x;
	double				dir_y;
	double				length_x;
	double				length_y;
	double				unit_length_x;
	double				unit_length_y;
	double				map_check_x;
	double				map_check_y;
	int					step_x;
	int					step_y;
	int					side;
	double				distance;
}						t_ray;

typedef struct s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				offset_pos_x;
	double				offset_pos_y;
	t_ray				ray;
	char				id;
}						t_player;

typedef struct s_hook_args
{
	t_player			*player;
}						t_hook_args;

typedef struct s_data	t_data;

typedef struct s_data
{
	t_file				*file;
	t_textures			*textures;
	t_map				*map;
	t_check				*check;
	t_mlx_data			*mlx_data;
	t_player			*player;
	int					(*render)(t_data *);
}						t_data;

/* structures/s_check */
t_check					*init_check_struct(t_data *data);
void					free_check(t_check *check);

/* structures/s_data */
t_data					*init_data_struct(void);

/* structures/s_file */
t_file					*init_file_struct(t_data *data);
void					free_file(t_file *file);

/* structures/s_map */
t_map					*init_map_struct(t_data *data);
void					free_map(t_map *map);

//structures/s_mlx
int						init_mlx(t_data *data);
int						free_mlx_data(t_mlx_data *mlx_data);

/* structures/s_player */
t_player				*init_player_struct(t_data *data);

/* structures/s_textures */
t_textures				*init_textures_struct(t_data *data);
void					free_textures(t_textures *textures);

#endif