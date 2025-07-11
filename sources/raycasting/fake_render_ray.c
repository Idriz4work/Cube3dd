/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_render_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:04:29 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/11 18:21:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DISTANCE_SCALING 2.0
#define NORMAL_HEIGHT 4
#define DARKNESS_INTENSITY 1.4
#define HEIGHT_SCALING 10
#define MAX_HEIGHT 15
#include "../../headers/cub3d.h"

static void	st_default_color(int type, int *r, int *g, int *b)
{
	*r = 0;
	*g = 0;
	*b = 0;
	if (type == NORTH_TEX)
	{
		*r = 193;
		*g = 193;
		*b = 193;
	}
	if (type == WEST_TEX)
		*r = 255;
	if (type == SOUTH_TEX)
		*g = 255;
	if (type == EAST_TEX)
		*b = 255;
	
}

static void	st_darken(double distance, int *r, int *g, int *b)
{
	double	i;

	i = 0;
	while (i < (distance / RENDER_DISTANCE) * DARKNESS_INTENSITY * 255)
	{
		*r -= 1;
		*g -= 1;
		*b -= 1;
		i++;
	}
	if (*r < 0)
		*r = 0;
	if (*g < 0)
		*g = 0;
	if (*b < 0)
		*b = 0;
}

int	make_color(t_ray *ray)
{
	int	r;
	int	g;
	int	b;
	int	color;

	st_default_color(ray->side, &r, &g, &b);
	st_darken(ray->wall_dist, &r, &g, &b);
	color = to_rgb(r, g, b);
	return (color);
}


/**
 * Displays some of the reys informaation on the screen
 * Each column of pixels is a color based on the side hit by that ray
 * Each column has a height, which indicates how far the wall is
*/
void	fake_render_ray(t_data *data, t_ray *ray)
{
	int	i;
	int	max;
	int	color;

	i = -1;
	max = NORMAL_HEIGHT + MAX_HEIGHT * (HEIGHT_SCALING - ray->wall_dist);
	color = make_color(ray);
	while (++i < max)
	{
		// my_pixel_put(data->image, ray->ray_x, WINDOW_HEIGHT - 1 - i, color);
		mlx_pixel_put(data->mlx, data->win, ray->ray_x, WINDOW_HEIGHT - 1 - i, color);
	}
}
