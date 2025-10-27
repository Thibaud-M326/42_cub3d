/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:36:02 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:13:25 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define WIDTH 1920
# define HEIGHT 1080
# define HITBOX_RADIUS 0.2

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/
typedef struct s_data		t_data;
typedef struct s_mlx_img	t_mlx_img;

//	src/hook/hook.c
int							deploy_mlx_hook(t_data *data);

//	src/player/player_collision
int							hitbox(t_data *data, double x, double y);

//	src/player/player_move.c
int							player_move(t_data *data);

//	src/player/player_turn.c
int							player_turn_left(t_data *data);
int							player_turn_right(t_data *data);

//	src/render/check_rays.c
int							check_ray_y(t_data *data, double next_y);
int							check_ray_x(t_data *data, double next_x);

//	src/render/draw_pixel.c
void						put_one_pixel_img(t_mlx_img *img, int x, int y,
								int color);
void						put_one_pixel(t_data *data, int x, int y,
								int color);
int							mix_color(int red, int green, int blue);

//	src/render/init_render.c
int							init_render(t_data *data);

//	src/render/raycasting_dda.c
int							raycasting_dda(t_data *data);

//	src/render/raycasting_init.c
int							raycasting_init(t_data *data);

//	src/render/raycasting.c
int							raycasting(t_data *data);

//	src/render/render.c
int							render(t_data *data);

//	src/texture/draw_texture.c
int							draw_texture(t_data *data, t_mlx_img *tex,
								int tex_x, int win_x);

//	src/texture/draw_textures.c
int							draw_textures(t_data *data, int x);

//	src/texture/get_texture_color.c
int							get_texture_color(t_data *data, t_mlx_img *tex,
								int tex_x, int win_y);

//	src/texture/get_texture_x.c
double						get_tex_x(t_data *data, t_mlx_img **tex);

//	src/texture/get_texture.c
t_mlx_img					*get_tex(t_data *data);

//	src/texture/load_texture.c
int							load_textures(t_data *data);

//	src/texture/ray_hit_point.c
int							ray_hit_point(t_data *data);

//	src/time/fps_count.c.c
int							fps_count(t_data *data);

//	src/time/get_current_time_ms.c
int							get_current_time_ms(void);

#endif
