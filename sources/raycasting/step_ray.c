/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:03:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/30 15:34:24 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

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
		if (pos == 0)
			delta = 1;
		else
			delta = 1 - (fmod(pos, 1.0));
	}
	else if (dir < 0)
	{
		if (pos == 0)
			delta = -1;
		else
			delta = 0 - (fmod(pos, 1.0));
	}
	else
		delta = 0.0;
	factor = delta / dir;
	return (factor);
}

/**
 * Fix edge fraying in north and west
 * If the ray is very close to the wall,
 * then put the ray onto that wall, and mark it as a map border
 * @return: 0 if ray continues normally
 * @return: 1 if ray was merged into wall and ray should stop
 */
static int	st_edge_adjust(t_ray *ray)
{
	if (ray->pos_x < 0.00001)
	{
		ray->pos_x = 0;
		ray->side = -1;
		return (1);
	}
	if (ray->pos_y < 0.00001)
	{
		ray->pos_y = 0;
		ray->side = -1;
		return (1);
	}
	return (0);
}

/**
 * Step the ray to the next edge
 * Checks how far to move the vector until the next line is crossed
 * by checking the distance to the next vertical
 * as well as the next horizontal line
 * Then chooses the smaller distance, and moves that far
 */
static int	st_single_step(t_ray *ray)
{
	double	x_factor;
	double	y_factor;
	double	factor;

	x_factor = st_axis_dist(fmod(ray->pos_x, 1.0), ray->vect_x);
	y_factor = st_axis_dist(fmod(ray->pos_y, 1.0), ray->vect_y);
	if (fabs(x_factor) < fabs(y_factor))
		factor = x_factor;
	else
		factor = y_factor;
	ray->pos_x += factor * ray->vect_x;
	ray->pos_y += factor * ray->vect_y;
	ray->wall_dist += sqrt(pow(factor * ray->vect_x, 2) \
+ pow(factor * ray->vect_y, 2));
	return (st_edge_adjust(ray));
}

/**
 * Moves the ray until it hits something
 * Moves in the direction of the rays vector
 * until it hits the Render Distance,
 * goes out of bounds,
 * or hits a wall
 * @param ray: the ray to operate on
*/
void	step_ray(t_data *data, t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < RENDER_DISTANCE)
	{
		if (st_single_step(ray))
			break ;
		if (oob_check((double)data->minfo->width, (double)data->minfo->height, \
ray->pos_x, ray->pos_y))
			break ;
		if (collision_check(data, ray))
			break ;
	}
}
