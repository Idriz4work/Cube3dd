/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:03:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/11 15:25:40 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

#define RAY_SNAP_DIST 0.00001
#define RENDER_DISTANCE 10

double delta_to_next_whole(double pos, double vec)
{
	// Get the fractional part using basic operators
	double	frac = fmod(pos, 1.0);

	if (frac < 0.0)
		frac = frac + 1.0;

	// Now compute distance based on direction
	if (vec > 0.0)
	{
		if (frac == 0.0)
			return (1.0);
		return (1.0 - frac);
	}
	else if (vec < 0.0) 
	{
		if (frac == 0.0) 
			return (-1.0);
		return (-frac);
	}
	else 
		return (0.0);
}

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

	delta = delta_to_next_whole(fmod(pos, 1.0), dir);
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

	x_factor = st_axis_dist(ray->delta_x, ray->vect_x);
	y_factor = st_axis_dist(ray->delta_y, ray->vect_y);
	if (fabs(x_factor) < fabs(y_factor))
	{
		printf("Crossing Y Axis\n");
		printf("Changing x from: %i to ", ray->int_x);
		if (ray->vect_x >= 0)
			ray->int_x++;
		else
			ray->int_x--;
		printf("%i...\n", ray->int_x);
		printf("Changing coords from %f %f to ", (double)ray->int_x + ray->delta_x, (double)ray->int_y + ray->delta_y);
		ray->delta_x = 0;
		factor = x_factor;
		// printf("Setting delta Y from %f to %f\n", ray->delta_y, fmod(ray->delta_y + y_factor * ray->vect_y, 1.0));
		ray->delta_y = fmod(ray->delta_y + x_factor * ray->vect_y, 1.0);
		printf("%f %f\n", (double)ray->int_x + ray->delta_x, (double)ray->int_y + ray->delta_y);
	}
	else
	{
		printf("Crossing X Axis\n");
		printf("Changing y from: %i to ", ray->int_y);
		if (ray->vect_y >= 0)
			ray->int_y++;
		else
			ray->int_y--;
		printf("%i...\n", ray->int_y);
		printf("Changing coords from %f %f to ", (double)ray->int_x + ray->delta_x, (double)ray->int_y + ray->delta_y);
		ray->delta_y = 0;
		factor = y_factor;
		// printf("Setting delta X from %f to %f\n", ray->delta_x, fmod(ray->delta_x + x_factor * ray->vect_x, 1.0));
		ray->delta_x = fmod(ray->delta_x + y_factor * ray->vect_x, 1);
		printf("%f %f\n", (double)ray->int_x + ray->delta_x, (double)ray->int_y + ray->delta_y);
	}
	ray->wall_dist += sqrt(pow(factor * ray->vect_x, 2) + pow(factor * ray->vect_y, 2));
	printf("NEW: Coords: %f, %f\n", (double)ray->int_x + ray->delta_x, (double)ray->int_y + ray->delta_y);
}

// Get delta_x (factor)
// choose smaller one
// increase map x and y
// change sideDist
// repeat until hit

static void	st_draw(t_data *data, t_ray *ray)
{
	mlx_pixel_put(data->mlx, data->win, \
(ray->int_x + ray->delta_x) * 32, \
(ray->int_y + ray->delta_y) * 32, \
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
	ray->int_x, ray->int_y))
			break ;
		if (collision_check(data, ray) != -1)
			break ;
		st_draw(data, ray);
	}
	printf("Ray Ended!\n\n");
}
