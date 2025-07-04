/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:39:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:39:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <X11/X.h>
# include "../includes/Libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include "image_struct.h"
# include "map_struct.h"
# include "data_struct.h"
# include "parsing.h"

// Because using M_PI gets marked wrong in VScode, but works in compiler
# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

# ifndef BONUS
#  define BONUS 0
# endif

// Window data
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768
# define TEXTURE_SIZE 64
# define WINDOW_TITLE "Cub3d by Lilly and Idris"

// Map characters
# define WALL '1'
# define EMPTY '0'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

// Key codes (adjust based on your system)
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

// Movement speed
# define MOVE_SPEED 0.05
# define ROT_SPEED 5
# define STEP_AMOUNT 5

// Rotations
# define DIR_U 0
# define DIR_L 90
# define DIR_D 180
# define DIR_R 270

// Texture indices
# define NORTH_TEX 0
# define SOUTH_TEX 1
# define EAST_TEX 2
# define WEST_TEX 3

// Colors
# define RED_CROSS 0xFF0000

// Error messages

// Parsing functions
// -> in parsing.h

// Movement functions
void	move(t_data *data, int direction);
void	turn(t_data *data, int delta);

// Raycasting functions

// Rendering functions
void	make_background(t_data *data);
void	make_minimap(t_data *data);
void	update_display(t_data *data);

// Utility functions
int		argc_check(int argc);
int		error(char *message, int ret);
void	free_charray(char **array);
int		atoi_limit(const char *nptr, int min, int max, int error);
int		to_rgb(int r, int g, int b);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	data_setup(t_data *data);
double	deg_to_rad(double degree);

// MLX event functions
int		key_hook(int keycode, t_data *data);
int		key_end(int keycode, t_data *data);
int		end_game(t_data *data);

#endif
