/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/09 18:29:33 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/****************************************************************************/
/*                                INCLUDE									*/
/****************************************************************************/
# include "structures.h"

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

/* structures/s_player */
t_player		*init_player_struct(t_data *data);

/* structures/s_textures */
t_textures		*init_textures_struct(t_data *data);
void			free_textures(t_textures *textures);

#endif