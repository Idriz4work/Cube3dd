/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:42:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/03 16:17:56 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#define BOX_SIZE 32
// Recommended: 8
#define PLAYER_SIZE 6
// Recommended: 4

// draw a box at <x> <y> with <color>
// Coordinates should be upscaled with BOX_SIZE
// (2,1 = 2*BOX_SIZE, 1*BOX_SIZE)
static void	st_draw_box(t_data *data, int color, int x, int y)
{
	int	i;
	int	j;

	if (y < 0 || y + BOX_SIZE > WINDOW_HEIGHT || \
x < 0 || x + BOX_SIZE > WINDOW_WIDTH)
		return ;
	i = -1;
	while (++i < BOX_SIZE)
	{
		j = -1;
		while (++j < BOX_SIZE)
			my_pixel_put(data->image, x + j, y + i, color);
	}
}

static void	st_draw_direction(t_data *data)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = (MOVE_SPEED * 5 * cos(deg_to_rad(data->dir - 90.0)));
	y = (MOVE_SPEED * 5 * sin(deg_to_rad(data->dir - 90.0)));
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

static void	st_draw_player(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = data->pos_x * BOX_SIZE;
	y = data->pos_y * BOX_SIZE;
	if (y < 0 || y + PLAYER_SIZE > WINDOW_HEIGHT || \
x < 0 || x + PLAYER_SIZE > WINDOW_WIDTH)
		return ;
	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
			my_pixel_put(data->image, x + j, y + i, to_rgb(252, 0, 0));
	}
	st_draw_direction(data);
}

void	make_minimap(t_data *data)
{
	int		x;
	int		y;
	char	type;
	int		color;

	y = -1;
	while (++y < data->minfo->height)
	{
		x = -1;
		while (++x < data->minfo->width)
		{
			type = data->minfo->grid[y][x];
			if (type == '1')
				color = to_rgb(127, 91, 60);
			else if (type == '0')
				color = to_rgb(185, 164, 146);
			else
				color = 0;
			if (color != 0)
				st_draw_box(data, color, x * BOX_SIZE, y * BOX_SIZE);
		}
	}
	st_draw_player(data);
}
