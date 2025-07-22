/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:42:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/22 03:17:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
# define MMAP_SIZE 150
# define MMAP_SCALE 10

// draw a box at <x> <y> with <color>
// Coordinates should be upscaled with BOX_SIZE
// (2,1 = 2*BOX_SIZE, 1*BOX_SIZE)
/*
static void	st_draw_box(t_data *data, int color, int x, int y)
{
	
}

static void	st_draw_direction(t_data *data)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = (MOVE_SPEED * 5 * cos(deg_to_rad(data->rot)));
	y = (MOVE_SPEED * 5 * sin(deg_to_rad(data->rot)));
	x = (data->pos_x + x) * BOX_SIZE;
	y = (data->pos_y + y) * BOX_SIZE;
	if (y < 0 || y + PLAYER_SIZE > WINDOW_HEIGHT || \
x < 0 || x + PLAYER_SIZE > WINDOW_WIDTH)
		return ;
	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
			my_pixel_put(data->image, x + j, y + i, to_rgb(184, 201, 50));
	}
}
*/

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
x + steps * (data->dir_x + data->plane_x) > (double)MMAP_SIZE || \
y + steps * (data->dir_y + data->plane_y) < 0 || \
y + steps * (data->dir_y + data->plane_y) > (double)MMAP_SIZE)
			break ;
		if (x + steps * (data->dir_x - data->plane_x) < 0 || \
x + steps * (data->dir_x - data->plane_x) > (double)MMAP_SIZE || \
y + steps * (data->dir_y - data->plane_y) < 0 || \
y + steps * (data->dir_y - data->plane_y) > (double)MMAP_SIZE)
			break ;
		my_pixel_put(data->image, (int)(x + steps * (data->dir_x + data->plane_x)), (int)(y + steps * (data->dir_y + data->plane_y)), to_rgb(0, 0, 0));
		my_pixel_put(data->image, (int)(x + steps * (data->dir_x - data->plane_x)), (int)(y + steps * (data->dir_y - data->plane_y)), to_rgb(0, 0, 0));
		steps += 0.5;
	}
}

static void	st_draw_player(t_data *data)
{
	int		x;
	int		y;

	y = (MMAP_SIZE / 2) - (MMAP_SCALE / 2) - 1;
	while (++y < (MMAP_SIZE / 2) + (MMAP_SCALE / 2))
	{
		x = (MMAP_SIZE / 2) - (MMAP_SCALE / 2) - 1;
		while (++x < (MMAP_SIZE / 2) + (MMAP_SCALE / 2))
		{
			my_pixel_put(data->image, x, y, to_rgb(102, 102, 102));
		}
	}
	st_draw_fov(data);
}

void	make_minimap(t_data *data)
{
	/*
	int		x;
	int		y;

	y = -1;
	while (++y < MMAP_SIZE)
	{
		x = -1;
		while (++x < MMAP_SIZE)
		{
			my_pixel_put(data->image, x, y, to_rgb(166, 130, 96));
		}
	}
		*/
	st_draw_player(data);
	st_draw_frame(data);
}
