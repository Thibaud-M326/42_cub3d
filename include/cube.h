/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/13 14:15:35 by thmaitre         ###   ########.fr       */
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

//src/hook/hook.c
int		deploy_mlx_hook(t_data *data);

//src/render/render.c
int		render(t_data *data);

//src/hook/hook.c
int		deploy_mlx_hook(t_data *data);

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

//src/render/draw_vertical_line.c
int		draw_vertical_line(t_data *data, int x);

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

#endif
