/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision_detection_helper.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:41:08 by marvin            #+#    #+#             */
/*   Updated: 2025/07/10 00:41:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Calculate the perpendicular wall distance
 * @param data: Game data containing player position
 * @param ray: The ray structure with DDA results
 */
void	st_calculate_wall_distance(t_data *data, t_ray *ray)
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
int	st_determine_wall_side(t_ray *ray)
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
