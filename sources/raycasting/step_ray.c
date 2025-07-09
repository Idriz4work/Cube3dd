/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:03:48 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/09 16:11:32 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Checks how many steps the vector eneds to cross an axis
 * 
 */
static double	st_axis_dist(double pos, double dir, char axis)
{
	double	limit;
	double	delta;
	double	factor;

	if (dir >= 0)
		limit = 1;
	else
		limit = 0;
	delta = limit - (fmod(pos, 1.0));
	printf("Travelling on %c axis: %.3f distance\n", axis, delta);
	factor = delta / dir;
	printf("%c Factor: %.3f\n", axis, factor);
	return (factor);
}

/**
 * In theory:
 * Take the x difference for the direction of the vector
 * this is the delta x, to move. You then divide your vectors x part
 * by your delta x, to get the amount of steps you need to move, to corss the y axis
*/
void	step_ray(t_ray *ray)
{
	double	x_factor;
	double	y_factor;
	double	factor;

	x_factor = st_axis_dist(ray->d_x, ray->ray_dir_x, 'X');
	y_factor = st_axis_dist(ray->d_y, ray->ray_dir_y, 'Y');
	if (fabs(x_factor) < fabs(y_factor))
	{
		printf("Crossing y axis\n");
		factor = x_factor;
	}
	else
	{
		printf("Crossing x axis\n");
		factor = y_factor;
	}
	ray->d_x += factor * ray->ray_dir_x;
	ray->d_y += factor * ray->ray_dir_y;
	printf("Moved Ray to %f %f\n", ray->d_x, ray->d_y);
}

int main(void)
{
	t_ray ray;

	ray.d_x = 0.3;
	ray.d_y = 0.0;
	ray.ray_dir_x = 0.15;
	ray.ray_dir_y = 0.15;
	step_ray(&ray);
	return (0);
}
