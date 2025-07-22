/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:42:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/22 22:10:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
# define MMAP_SIZE 150
# define PLAYER_SIZE 5
# define VIEW_DISTANCE 10

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
		my_pixel_put(data->image, (int)(x + steps * (data->dir_x + data->plane_x)), (int)(y + steps * (data->dir_y + data->plane_y)), to_rgb(0, 0, 0));
		my_pixel_put(data->image, (int)(x + steps * (data->dir_x - data->plane_x)), (int)(y + steps * (data->dir_y - data->plane_y)), to_rgb(0, 0, 0));
		steps += 0.5;
	}
}

static void	st_draw_player(t_data *data)
{
	int		x;
	int		y;

	y = (MMAP_SIZE / 2) - (PLAYER_SIZE / 2) - 1;
	while (++y < (MMAP_SIZE / 2) + (PLAYER_SIZE / 2))
	{
		x = (MMAP_SIZE / 2) - (PLAYER_SIZE / 2) - 1;
		while (++x < (MMAP_SIZE / 2) + (PLAYER_SIZE / 2))
		{
			my_pixel_put(data->image, x, y, to_rgb(102, 102, 102));
		}
	}
	st_draw_fov(data);
}

static double	st_convert(int current, int max)
{
	double adjust;
	double factor;

	adjust = (double)current - (double)(max / 2);
	factor = adjust / (double)max;
	return (factor * VIEW_DISTANCE);
}

static int st_col(t_data *data, double posx, double posy)
{
	int x;
	int y;

	x = floor(posx);
	y = floor(posy);
	if (x < 0 || y < 0 || x > data->minfo->width - 1 || y > data->minfo->height - 1)
		return (0);
	if (data->minfo->grid[y][x] == '1')
		return(to_rgb(171, 144, 101));
	if (data->minfo->grid[y][x] == ' ')
		return(0);
	return(to_rgb(221, 194, 151));
}

// 14	-1
// 32	0
// 70	1

static void st_draw_blocks(t_data *data)
{
	int	x;
	int y;
	double posx;
	double	posy;
	int	color;

	y = -1;
	while (++y < MMAP_SIZE)
	{
		x = -1;
		while (++x < MMAP_SIZE)
		{
			posx = data->pos_x + st_convert(x, MMAP_SIZE);
			posy = data->pos_y + st_convert(y, MMAP_SIZE);
			color = st_col(data, posx, posy);
			if (color != 0)
				my_pixel_put(data->image, x, y, color);	
		}
	}
}

void	make_minimap(t_data *data)
{
	st_draw_blocks(data);
	st_draw_player(data);
	st_draw_frame(data);
}
