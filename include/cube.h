/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/17 18:17:33 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/****************************************************************************/
/*                                INCLUDE									*/
/****************************************************************************/
# include "structures.h"
# include <stdbool.h>

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/
/* exit/free_exit */
void	free_and_exit_debug(t_data *data, char *msg, int err, const char *file,
			int line, const char *func);

/* exit/utils */
void	free_strs(char **strs);

# define free_and_exit(data, msg, err) \
	free_and_exit_debug(data, msg, err, __FILE__, __LINE__, __func__)

//src/render/render.c
int		render(t_data *data);

//src/hook/hook.c
int		deploy_mlx_hook(t_data *data);

//src/hook/player_move_KEYPRESS.c
int		player_moove_KEYPRESS(t_data *data);

//src/hook/player_move.c
int		player_move_forward(t_data *data);
int		player_move_backward(t_data *data);
int		player_turn_left(t_data *data);
int		player_turn_right(t_data *data);

//structures/s_mlx
int		init_mlx(t_data *data);
int		free_mlx_data(t_mlx_data *mlx_data);

//src/render/draw_floor_ceiling.c
int		draw_floor_ceiling(t_data *data);

//src/render/draw.c
void	put_one_pixel(t_data *data, int x, int y, int color);
int		mix_color(int red, int green, int blue);

//structures/s_mlx
int		init_mlx(t_data *data);
int		free_mlx_data(t_mlx_data *mlx_data);

//src/render/render.c
int		render(t_data *data);

//src/render/raycasting_dda.c
int		raycasting_dda(t_data *data);

//src/render/raycasting_init.c
int		raycasting_init(t_data *data);

//src/render/raycasting.c
int		raycasting(t_data *data);

/* print */
void	print_textures(t_data *data);
void	print_map(t_data *data);
void	print_free(t_data *data);

//src/texture/draw_textures.c
int		draw_textures(t_data *data, int x);

//src/texture/get_texture_color.c
double	get_texture_color(int y, int line_start, int line_end, int tex_x, t_mlx_img *tex);

//src/texture/get_texture_x.c
double	get_tex_x(t_data *data, t_mlx_img **tex);

//src/texture/load_texture.c
int		load_textures(t_data *data);

//src/texture/ray_hit_point.c
int		ray_hit_point(t_data *data);

#endif
