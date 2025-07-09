/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:03:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/09 19:05:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

#define RAY_SNAP_DIST 0.00001

/**
 * Checks how many steps the vector eneds to cross an axis
 * 
 * ISSUE:
 * When pos is close to 1, and dir is positive
 * or pos is close to 0 and dir is negative
 * Then Delta becomes 0, which it shouldnt be unless dir is 0
 * Basically, being at the edges means seeing the edge as already reached
 * Meaning that no movement is performed
 * SOLUTION:
 * Snapping - 
 * when pos very close to edge (1 or 0), 
 * and dir not being 0, 
 * set delta x to be +/- 1, 
 * in addtition to whatever difference there is from pos to the closer edge
 * 
 * Take the delta, how much to move,
 * on this line to reach the edge towards the vector direction,
 * or the nexte edge, if you are on an extreme value, like 0 or 1
 * Then divide this delta by the distance of the vector
 * essentially doing
 * (distance) / (distance / step) = (steps)
 * to figure out how many times to move with the vector, 
 * to reach the next edge
 * Returns this factor
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
	printf("Moved Ray to %f %f\n\n", ray->d_x, ray->d_y);
}

/**
 * In theory:
*/
void	step_ray(t_ray *ray)
{
	st_single_step(ray);
	st_single_step(ray);
	st_single_step(ray);
}

int main(void)
{
	t_ray ray;

	ray.d_x = 1.0;
	ray.d_y = 1.6;
	ray.ray_dir_x = 0;
	ray.ray_dir_y = 1;
	step_ray(&ray);
	return (0);
}

/**
 * rm a.out ; cc -Wall -Wextra -Werror sources/raycasting/step_ray.c -lm ; clear ; ./a.out
 */