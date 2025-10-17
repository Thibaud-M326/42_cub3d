/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:21:37 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/17 20:00:13 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

/* MINIMAP */
// # define VOID_MMAP 0x610000
# define VOID_MMAP 0x2b3a3d

// # define GROUND_MMAP 0xDEDEDE
# define GROUND_MMAP 0x406682

# define BORDER_MMAP 0xFF0000

// # define WALLS_MMAP 0x696969
# define WALLS_MMAP 0xc3e1f7

# define PLAYER_MMAP 0xFF0000

# define CELL_SIZE 9
# define DEAD_ZONE_RATIO 0.25

/* minimap/draw */
void	draw_minimap(t_data *data);

/* minimap/update */
void	update_map(t_data *data);

/* minimap/utils */
int		get_map_line_len(char *line);
int		get_map_max_width(char **map);
void	clear_image(t_mlx_img *img, int color);
void	draw_cell(t_mlx_img *img, int x, int y, int color);

#endif