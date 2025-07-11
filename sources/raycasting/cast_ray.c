/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:40:02 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/11 14:51:11 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/cub3d.h"

#include "../../headers/cub3d.h"

/** 
 * Initialise data for the ray
 * @param: ray: the ray to be initialised
 * @param: x: the x position of this ray on the screen
*/
static void	st_setup_ray(t_data *data, t_ray *ray, int x)
{
	ray->vect_x = 0;
	ray->vect_y = 0;
	ray->int_x = (int)data->pos_x;
	ray->int_y = (int)data->pos_y;
	ray->delta_x = data->pos_x - (int)data->pos_x;
	ray->delta_y = data->pos_y - (int)data->pos_y;
	printf("Ray starting at %i %i %f %f\n", ray->int_x, ray->int_y, ray->int_x + ray->delta_x, ray->int_y + ray->delta_y);
	ray->side = 0;
	ray->wall_dist = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->ray_x = x;
	ray->wall_x = 0;
}

/**
 * Get the vector for the ray
 * Get the factor, of how much of the plane vector needs to be added
   to go from point + dir to the point of this vector on the screen
*/
static void	st_get_vector(t_data *data, t_ray *ray)
{
	double	factor;

	factor = (((double)ray->ray_x * 2) / (WINDOW_WIDTH - 1)) - 1;
	ray->vect_x = data->dir_x + (factor * data->plane_x);
	ray->vect_y = data->dir_y + (factor * data->plane_y);
}

/** 
 * Casts out a ray and performs collision detection
 * @param: ray: the ray to be sent out
 * @param: x: the x position of this ray on the screen
*/
void	cast_ray(t_data *data, t_ray *ray, int x)
{
	st_setup_ray(data, ray, x);
	st_get_vector(data, ray);
	step_ray(data, ray);
}
