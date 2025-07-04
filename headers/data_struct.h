/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:42:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:42:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include "image_struct.h"
# include "map_struct.h"

# define NUM_TEXTURES 4

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*text_buf[NUM_TEXTURES];
	// Player position and direction
	double	pos_x;
	double	pos_y;
	double	dir;
	double	plane_x;
	double	plane_y;
	// Image buffer for rendering
	t_img	*image;
	int		**pixels_map;
	t_map	*minfo;
}	t_data;

// Unused attributes so far: plane_x, plane_y, pixels_map

#endif