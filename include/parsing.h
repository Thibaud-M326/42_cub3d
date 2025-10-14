/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:55:18 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/14 18:46:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* parsing/check_map */
int		is_map_valid(t_data *data);

/* parsing/color */
void	set_color(t_data *data, char id);
void	check_color_format(t_data *data);
char	*get_color(t_data *data);

/* parsing/file_utils */
int		count_lines(t_data *data);
void	err_handler(t_data *data);
void	get_path_file(char *input, t_data *data);

/* parsing/file */
void	check_file(char *input, t_data *data);

/* parsing/identifiers_utils */
void	open_xpm(t_data *data, char *path);
void	is_identifier_texture(t_data *data, char id, char *path);
void	check_duplicate(t_data *data, char id);
void	check_color_identifiers(t_data *data, int *i);

/* parsing/identifiers */
void	check_identifier(t_data *data, char id);
void	search_identifier(t_data *data);

/* parsing/init_player_dir */
int		init_player_dir(t_data *data);

/* parsing/input */
void	parse_input(int ac, char **av, t_data *data);

/* parsing/map */
void	check_map_line(t_data *data);
void	check_map_order(int i, t_data *data);

/* parsing/textures */
void	check_texture_ext(t_data *data, char *path);
char	*get_texture_path(t_data *data);

/* parsing/utils */
void	is_spawn(t_data *data, char c);
bool	is_player_spawn(t_data *data, char c, int x, int y);
bool	are_all_identifiers_true(t_data *data);
bool	is_available_char_identifier(char c);
bool	is_available_char_map(char c);

#endif