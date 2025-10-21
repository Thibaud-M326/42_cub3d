/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:21:37 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/21 18:13:15 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

/****************************************************************************/
/*                                DEFINE									*/
/****************************************************************************/

# define VOID_MMAP 0x303030
# define GROUND_MMAP 0xc7d0cc
# define BORDER_MMAP 0x303030
# define WALLS_MMAP 0x808080
# define PLAYER_MMAP 0xFF0000
# define CELL_SIZE_MIN 10
# define CELL_SIZE_MAX 30
# define DEAD_ZONE_RATIO 0.25

/****************************************************************************/
/*                                FUNCTIONS									*/
/****************************************************************************/

/* minimap/draw */
void	draw_minimap(t_data *data);

/* minimap/update */
void	update_map(t_data *data);

/* minimap/utils */
int		get_map_line_len(char *line);
int		get_map_max_width(char **map);
void	clear_image(t_mlx_img *img, int color);
void	draw_cell(t_data *data, int x, int y, int color);

#endif