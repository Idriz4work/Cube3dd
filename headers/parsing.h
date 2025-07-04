/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:30:32 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:25:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// This is the header file for the load_map() function, as well as its util
// It is used to find, open and load the contents of a specified file
// It stores that information in the structure from headers/map_struct.h

// For NULL:
# include <stdlib.h>
// For printf:
# include <stdio.h>
// For opening files:
# include <fcntl.h>
// For the mapfile object
# include "map_struct.h"
// For many utility functions
# include "../includes/Libft/libft.h"
// For getting input from the mapfile
# include "get_next_line.h"
// For saving the input as a linked list
# include "charlist_utils.h"
// For checking if texture images can be opened
# include "../includes/minilibx-linux/mlx.h"

# define FILE_FORMAT ".cub"

// Values, that load_map will return, indicating errors:
# define ERR_MAPFILE_NULL 1
# define ERR_MAPFILE_SHORT 2
# define ERR_MAPFILE_FORM 3
# define ERR_MAPFILE_OPEN 4
# define ERR_MAPFILE_SYNTAX 5
# define ERR_MAPFILE_TEXFILE 6
# define ERR_MAPFILE_XPMIMG 7
# define ERR_MAPFILE_DOUBLE 8
# define ERR_MAPFILE_UNFIN 9
# define ERR_MAPFILE_INVCHAR 10
# define ERR_MAPFILE_ALOCFAIL 11
# define ERR_MAPGRID_PLOW 12
# define ERR_MAPGRID_PHIGH 13
# define ERR_MAPGRID_FLOOD 14

// Change this between 1 (active) and 0 to activate extra print output
# define MAPFILE_EXT_OUT 1

int			mapfile_open(char *filename, int *status);
int			load_map(char *filename, t_map *map);
void		mapfile_init(t_map *map);
void		mapfile_free(t_map *map);
int			mapfile_content(int mapfd, t_map *map);
int			mapfile_check_texture(char *buffer, char **target);
int			mapfile_check_color(char *buffer, int (*target)[3]);
int			atoi_limit(const char *nptr, int min, int max, int error);
int			find_cins(char *string, char target);
int			mapfile_build_list(t_map *map, t_charlist **lst, char *buffer);
int			mapfile_ll_to_grid(t_charlist **lst, t_map *map);
void		mapfile_complain(int type);
int			mapfile_verify_grid(t_map *map);

#endif
