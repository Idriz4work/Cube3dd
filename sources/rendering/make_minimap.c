/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:42:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 04:40:54 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	st_oob_check(t_data *data, double x, double y, double steps)
{
	double	width;
	double	height;

	width = x + steps * (data->dir_x + data->plane_x);
	height = y + steps * (data->dir_y + data->plane_y);
	if (width < 0 || width > (double)(MMAP_SIZE - 1) || \
height < 0 || height > (double)(MMAP_SIZE - 1))
		return (1);
	width = x + steps * (data->dir_x - data->plane_x);
	height = y + steps * (data->dir_y - data->plane_y);
	if (width < 0 || width > (double)(MMAP_SIZE - 1) || \
height < 0 || height > (double)(MMAP_SIZE - 1))
		return (1);
	return (0);
}

static void	st_draw_fov(t_data *data)
{
	double		x;
	double		y;
	double		steps;

	steps = 0;
	x = (double)(MMAP_SIZE / 2);
	y = (double)(MMAP_SIZE / 2);
	while (steps < 40)
	{
		if (st_oob_check(data, x, y, steps))
			break ;
		my_pixel_put(data->image, (int)(x + steps * \
(data->dir_x + data->plane_x)), (int)(y + steps * \
(data->dir_y + data->plane_y)), MMAP_C_FOV);
		my_pixel_put(data->image, (int)(x + steps * \
(data->dir_x - data->plane_x)), (int)(y + steps * \
(data->dir_y - data->plane_y)), MMAP_C_FOV);
		steps += 0.25;
	}
}

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

void	make_minimap(t_data *data)
{
	minimap_background(data);
	st_draw_fov(data);
	minimap_frame(data);
	st_draw_player(data);
}
