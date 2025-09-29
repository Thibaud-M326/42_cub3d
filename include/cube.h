/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/29 20:21:11 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdbool.h>

typedef struct s_file
{
	char	*filename;
	char	*ext;
	char	*map;
	int		fd;
}			t_file;

typedef struct s_data
{
	t_file	*file;
}			t_data;

/* input */
void		print_error(t_data *data, int err);
bool		check_input(char *input, t_data *data);

/* free_file */
t_file		*init_file_struct(t_data *data);
void		free_file(t_file *file);

/* s_data */
t_data		*init_data_struct(void);
void		free_and_exit(t_data *data, int err);

/* map */
void		check_map_file(char *input, t_data *data);

#endif