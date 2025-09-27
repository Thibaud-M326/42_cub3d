/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:03:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/28 00:10:19 by jmagand          ###   ########.fr       */
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
bool		print_error(int err);
bool		check_input(char *input, t_file **file);
void		check_map(char *input, t_file *file);

/* free_file */
t_file		*init_file_struct(char *filename, char *ext, t_file *file);
void		free_file(t_file *file);

#endif