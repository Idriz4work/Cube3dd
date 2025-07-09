/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision_detection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:33:45 by marvin            #+#    #+#             */
/*   Updated: 2025/07/10 00:33:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Calculate the delta distances for DDA algorithm
 * @param ray: The ray structure to calculate delta distances for
 */
static void	st_calculate_delta_distances(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

/**
 * Calculate step direction and initial side distances
 * @param data: Game data containing player position
 * @param ray: The ray structure to set up
 */
static void	st_setup_dda(t_data *data, t_ray *ray)
{
	ray->map_x = (int)data->pos_x;
	ray->map_y = (int)data->pos_y;
	
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->pos_x) * ray->delta_dist_x;
	}
	
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->pos_y) * ray->delta_dist_y;
	}
}

/**
 * Perform DDA algorithm to find wall collision
 * @param data: Game data containing the map
 * @param ray: The ray structure to perform DDA on
 * @return: 1 if wall hit, 0 if no wall found (shouldn't happen in valid map)
 */
static int	st_perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		// Jump to next map square, either in x-direction, or in y-direction
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;  // X-side hit
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;  // Y-side hit
		}
		
		// Check if ray has hit a wall
		if (ray->map_x >= 0 && ray->map_x < data->minfo->width &&
			ray->map_y >= 0 && ray->map_y < data->minfo->height &&
			data->minfo->grid[ray->map_y][ray->map_x] == '1')
		{
			hit = 1;
		}
		
		// Safety check to prevent infinite loop
		if (ray->map_x < 0 || ray->map_x >= data->minfo->width ||
			ray->map_y < 0 || ray->map_y >= data->minfo->height)
		{
			hit = 1;  // Treat map boundary as wall
		}
	}
	return (hit);
}

/**
 * Calculate the perpendicular wall distance
 * @param data: Game data containing player position
 * @param ray: The ray structure with DDA results
 */
static void	st_calculate_wall_distance(t_data *data, t_ray *ray)
{
	if (ray->side == 0)  // X-side hit
	
		ray->wall_dist = (ray->map_x - data->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	
	else  // Y-side hit
	
		ray->wall_dist = (ray->map_y - data->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	
}

/**
 * Determine which side of the grid cell was hit
 * @param ray: The ray structure with collision information
 * @return: Integer representing the side (0=NORTH, 1=WEST, 2=SOUTH, 3=EAST)
 */
static int	st_determine_wall_side(t_ray *ray)
{
	if (ray->side == 0)  // X-side hit
	{
		if (ray->step_x > 0)
			return (3);  // EAST_TEX
		else
			return (1);  // WEST_TEX
	}
	else  // Y-side hit
	{
		if (ray->step_y > 0)
			return (2);  // SOUTH_TEX
		else
			return (0);  // NORTH_TEX
	}
}

/**
 * Perform ray collision detection and return ray information
 * @param data: Game data containing player position and map
 * @param ray: The ray structure to perform collision detection on
 * @param result: Array to store [distance_multiplier, wall_side]
 * @return: Pointer to the result array
 */
int	*get_ray_collision_info(t_data *data, t_ray *ray, int result[2])
{
	double	vector_length;
	
	// Calculate delta distances for DDA
	st_calculate_delta_distances(ray);
	
	// Setup DDA parameters
	st_setup_dda(data, ray);
	
	// Perform DDA to find wall collision
	st_perform_dda(data, ray);
	
	// Calculate perpendicular wall distance
	st_calculate_wall_distance(data, ray);
	
	// Calculate vector length
	vector_length = sqrt(ray->ray_dir_x * ray->ray_dir_x + ray->ray_dir_y * ray->ray_dir_y);
	
	// Store results
	result[0] = (int)(ray->wall_dist * vector_length);  // Distance multiplier
	result[1] = st_determine_wall_side(ray);           // Wall side
	
	// Update ray structure with calculated values for rendering
	ray->side = result[1];
	
	return (result);
}
