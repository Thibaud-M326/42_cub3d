/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/27 15:12:02 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define WIDTH 1920
# define HEIGHT 1080
# define HITBOX_RADIUS 0.2

/****************************************************************************/
/*                                INCLUDE									*/
/****************************************************************************/
# include "structures.h"
# include <stdbool.h>

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/

//	src/exit/free_exit.c
void	free_and_exit(t_data *data, char *msg, int err);
void	free_and_exit_no_error(t_data *data);

//	src/exit/utils.c
void	free_strs(char **strs);

//	src/hook/hook.c
int		deploy_mlx_hook(t_data *data);

//	src/player/player_collision
int		hitbox_clear(t_data *data, double x, double y);

//	src/player/player_move.c
int		player_move(t_data *data);

//	src/player/player_turn.c
int		player_turn_left(t_data *data);
int		player_turn_right(t_data *data);

//	src/render/check_rays.c
int		check_ray_y(t_data *data, double next_y);
int		check_ray_x(t_data *data, double next_x);

//	src/render/init_render.c
int		init_render(t_data *data);

//	src/render/draw_pixel.c
void	put_one_pixel_img(t_mlx_img *img, int x, int y, int color);
void	put_one_pixel(t_data *data, int x, int y, int color);
int		mix_color(int red, int green, int blue);

//	src/render/raycasting_dda.c
int		raycasting_dda(t_data *data);

//	src/render/raycasting_init.c
int		raycasting_init(t_data *data);

//	src/render/raycasting.c
int		raycasting(t_data *data);

//	src/render/render.c
int		render(t_data *data);

//	src/texture/draw_textures.c
int		draw_textures(t_data *data, int x);

//src/texture/get_texture_color.c
int		get_texture_color(t_data *data, t_mlx_img *tex, int y, int tex_x);

//src/texture/get_texture_x.c
double	get_tex_x(t_data *data, t_mlx_img **tex);

//src/texture/load_texture.c
int		load_textures(t_data *data);

//src/texture/ray_hit_point.c
int		ray_hit_point(t_data *data);

//src/time/get_current_time_ms.c
int		get_current_time_ms(void);
int		fps_count(t_data *data);

#endif
