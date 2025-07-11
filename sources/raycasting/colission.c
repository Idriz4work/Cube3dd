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

#define COL_SENS 0.01

/**
 * Calculate the perpendicular wall distance
 * @param data: Game data containing player position
 * @param ray: The ray structure with DDA results
 */

static int	st_wall_check(t_data *data, int x, int y)
{
	// printf("Checking %i %i\n", x, y);
	if (x < 0 || x > data->minfo->width)
		return (0);
	if (y < 0 || y > data->minfo->height)
		return (0);
	if (data->minfo->grid[y][x] == '1')
		return (1);
	// printf("Is free\n");
	return (0);
}

int	collision_check(t_data *data, t_ray *ray)
{
	int	x;
	int	y;

	x = (int)ray->int_x;
	y = (int)ray->int_y;
	if (!st_wall_check(data, x, y))
	{
		printf("Free at: %i %i \n", x, y);
		return (-1);
	}
	printf("Wall at: %i %i \n", x, y);
	if (fmod(x, 1) > 1 - COL_SENS || fmod(x, 1) < COL_SENS)	
	{
		if (ray->vect_x >= 0)
			ray->side = WEST_TEX;
		else
			ray->side = EAST_TEX;
	}
	else if (fmod(y, 1) > 1 - COL_SENS || fmod(y, 1) < COL_SENS)	
	{
		if (ray->vect_y >= 0)
			ray->side = SOUTH_TEX;
		else
			ray->side = NORTH_TEX;
	}
	else
	{
		ray->side = -1;
		return (-1);
	}
	return (0);
}

// Moving up or right, does not increas x or y enough to count as in the next square

// if either coordinate is extreme
// change that coordinate by a miniscule fraction of the vector