/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:42:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/22 22:43:49 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/** */
static void st_hor_line(t_data *data, int x, int y, int color)
{
	while (++x < MMAP_SIZE)
		my_pixel_put(data->image, x, y, color);
}

static void st_vert_line(t_data *data, int x, int y, int color)
{
	while (++y < MMAP_SIZE)
		my_pixel_put(data->image, x, y, color);
}

static void	st_draw_frame(t_data *data)
{
	int	x;
	int y;
	int	color1;
	int	color2;

	color1 = to_rgb(171, 144, 101);
	color2 = to_rgb(219, 200, 169);
	y = -1;
	while (++y < 5)
		st_hor_line(data, 0, y, color1);
	y = MMAP_SIZE - 6;
	while (++y < MMAP_SIZE)
		st_hor_line(data, 0, y, color1);
	x = -1;
	while (++x < 5)
		st_vert_line(data, x, 0, color1);
	x = MMAP_SIZE - 6;
	while (++x < MMAP_SIZE)
		st_vert_line(data, x, 0, color1);
	st_hor_line(data, 0, 2, color2);
	st_hor_line(data, 0, MMAP_SIZE - 3, color2);
	st_vert_line(data, 2, 0, color2);
	st_vert_line(data, MMAP_SIZE - 3, 0, color2);
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
		if (x + steps * (data->dir_x + data->plane_x) < 0 || \
x + steps * (data->dir_x + data->plane_x) > (double)(MMAP_SIZE - 1) || \
y + steps * (data->dir_y + data->plane_y) < 0 || \
y + steps * (data->dir_y + data->plane_y) > (double)(MMAP_SIZE - 1))
			break ;
		if (x + steps * (data->dir_x - data->plane_x) < 0 || \
x + steps * (data->dir_x - data->plane_x) > (double)(MMAP_SIZE - 1) || \
y + steps * (data->dir_y - data->plane_y) < 0 || \
y + steps * (data->dir_y - data->plane_y) > (double)(MMAP_SIZE - 1))
			break ;
		my_pixel_put(data->image, (int)(x + steps * (data->dir_x + data->plane_x)), (int)(y + steps * (data->dir_y + data->plane_y)), to_rgb(0, 100, 0));
		my_pixel_put(data->image, (int)(x + steps * (data->dir_x - data->plane_x)), (int)(y + steps * (data->dir_y - data->plane_y)), to_rgb(0, 100, 0));
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
		{
			my_pixel_put(data->image, x, y, to_rgb(102, 102, 102));
		}
	}
	st_draw_fov(data);
}

void	make_minimap(t_data *data)
{
	minimap_background(data);
	st_draw_player(data);
	st_draw_frame(data);
}
