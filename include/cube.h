/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/28 23:27:04 by jmagand          ###   ########.fr       */
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

/* input */
void		print_error(int err);
bool		check_input(char *input, t_file **file);

/* free_file */
t_file		*init_file_struct(char *filename, char *ext, t_file *file);
void		free_file(t_file *file);
void		free_and_exit(t_file *file, int err);

/* map */
void		check_map_file(char *input, t_file *file);

#endif