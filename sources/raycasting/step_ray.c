/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:03:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/10 20:46:35 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

#define RAY_SNAP_DIST 0.00001
#define RENDER_DISTANCE 10

/**
 * Checks how many steps the vector needs to cross an axis
 * Take the delta, how much to move,
 * on this line to reach the edge towards the vector direction,
 * or the nexte edge, if you are on an extreme value, like 0 or 1
 * Then divide this delta by the distance of the vector
 * essentially doing
 * (distance) / (distance / step) = (steps)
 * to figure out how many times to move with the vector, 
 * to reach the next edge
 * @param: pos - the position along a specific axis, from 0.0 -to 0.99999
 * @param: dir - the part of the vector for this axis
 * @return: the factor how many times to move the vector until crossing
 */
static double	st_axis_dist(double pos, double dir)
{
	double	delta;
	double	factor;

	if (dir > 0)
	{
		if (pos >= (float)1 - RAY_SNAP_DIST)
			delta = 1;
		else
			delta = 1 - (fmod(pos, 1.0));
	}
	else
	{
		if (pos <= RAY_SNAP_DIST)
			delta = -1;
		else
			delta = 0 - (fmod(pos, 1.0));
	}
	factor = delta / dir;
	return (factor);
}

/**
 * Step the ray to the next edge
 * Checks how far to move the vector until the next line is crossed
 * by checking the distance to the next vertical
 * as well as the next horizontal line
 * Then chooses the smaller distance, and moves that far
 */
static void	st_single_step(t_ray *ray)
{
	double	x_factor;
	double	y_factor;
	double	factor;

	x_factor = st_axis_dist(fmod(ray->d_x, 1.0), ray->ray_dir_x);
	y_factor = st_axis_dist(fmod(ray->d_y, 1.0), ray->ray_dir_y);
	if (fabs(x_factor) < fabs(y_factor))
		factor = x_factor;
	else
		factor = y_factor;
	ray->d_x += factor * ray->ray_dir_x;
	ray->d_y += factor * ray->ray_dir_y;
	ray->wall_dist += sqrt(pow(factor * ray->ray_dir_x, 2) + pow(factor * ray->ray_dir_y, 2));
}

static void	st_draw(t_data *data, t_ray *ray)
{
	mlx_pixel_put(data->mlx, data->win, ray->d_x * 32 , ray->d_y * 32, \
	to_rgb(255, 0, 255));
}

/**
 * Moves the ray until it hits something
 * Moves in the direction of the rays vector
 * until it hits the Render Distance,
 * goes out of bounds,
 * or hits a wall (last part not implemented)
*/
void	step_ray(t_data *data, t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < RENDER_DISTANCE)
	{
		st_single_step(ray);
		if (oob_check((double)data->minfo->width, (double)data->minfo->height, \
	ray->d_x, ray->d_y))
			break ;
		if (collision_check(data, ray) != -1)
			break ;
		st_draw(data, ray);
	}
}
