/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:42:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 15:05:26 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Checks if the coordinates are out of bounds of the mmap
 * @param data: Data structure, for ray direction
 * @param steps: How many times the ray has stepped 
 */
static int	st_oob_check(t_data *data, double steps)
{
	double	width;
	double	height;
	double	pos;

	pos = (double)(MMAP_SIZE / 2);
	width = pos + steps * (data->dir_x + data->plane_x);
	height = pos + steps * (data->dir_y + data->plane_y);
	if (width < 0 || width > (double)(MMAP_SIZE - 1) || \
height < 0 || height > (double)(MMAP_SIZE - 1))
		return (1);
	width = pos + steps * (data->dir_x - data->plane_x);
	height = pos + steps * (data->dir_y - data->plane_y);
	if (width < 0 || width > (double)(MMAP_SIZE - 1) || \
height < 0 || height > (double)(MMAP_SIZE - 1))
		return (1);
	return (0);
}

/**
 * Draws two lines representing the edges of the players vision
 */
static void	st_draw_fov(t_data *data)
{
	double		pos;
	double		steps;

	pos = (double)(MMAP_SIZE / 2);
	steps = 0;
	while (steps < 40)
	{
		if (st_oob_check(data, steps))
			break ;
		my_pixel_put(data->image, (int)(pos + steps * \
(data->dir_x + data->plane_x)), (int)(pos + steps * \
(data->dir_y + data->plane_y)), MMAP_C_FOV);
		my_pixel_put(data->image, (int)(pos + steps * \
(data->dir_x - data->plane_x)), (int)(pos + steps * \
(data->dir_y - data->plane_y)), MMAP_C_FOV);
		steps += 0.25;
	}
}

/**
 * Draws a square at the middle of the minimap
 */
static void	st_draw_player(t_data *data)
{
	int		x;
	int		y;

	y = (MMAP_SIZE / 2) - (MMAP_PLAYER_SIZE / 2) - 1;
	while (++y < (MMAP_SIZE / 2) + (MMAP_PLAYER_SIZE / 2))
	{
		x = (MMAP_SIZE / 2) - (MMAP_PLAYER_SIZE / 2) - 1;
		while (++x < (MMAP_SIZE / 2) + (MMAP_PLAYER_SIZE / 2))
			my_pixel_put(data->image, x, y, MMAP_C_PLAYER);
	}
}

/**
 * Draws the minimap
 */
void	mmap_bonus(t_data *data)
{
	mmap_tiles_bonus(data);
	st_draw_fov(data);
	mmap_frame_bonus(data);
	st_draw_player(data);
}
