/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:40:02 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/08 18:52:52 by sikunne          ###   ########.fr       */
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
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->d_x = (double)data->pos_x;
	ray->d_y = (double)data->pos_y;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->wall_dist = 0;
	ray->wall_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->tex_x = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->wall_x = x;
}

/**
 * Get the vector for the ray
 * Get the factor, of how much of the plane vector needs to be added
   to go from point + dir to the point of this vector on the screen
*/
static void	st_get_vector(t_data *data, t_ray *ray)
{
	double	factor;

	factor = ((ray->wall_x * 2) / (WINDOW_WIDTH - 1)) - 1;
	ray->ray_dir_x = data->dir_x + (factor * data->plane_x);
	ray->ray_dir_y = data->dir_y + (factor * data->plane_y);
	ray->d_x += ray->ray_dir_x;
	ray->d_y += ray->ray_dir_y;
	mlx_pixel_put(data->mlx, data->win, data->pos_x + ray->d_x * 32, data->pos_y + ray->d_y * 32, to_rgb(255, 0, 0)); // REMOVE
}

/** 
 * Casts out a ray
 * @param: ray: the ray to be sent out
 * @param: x: the x position of this ray on the screen
*/
void	cast_ray(t_data *data, t_ray *ray, int x)
{
	st_setup_ray(data, ray, x);
	st_get_vector(data, ray);
}
