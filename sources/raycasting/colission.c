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
 * @return: 1 if wall at x, y
 * @return: 0 if not, or out of range
 */

static int	st_wall_check(t_data *data, int x, int y)
{
	if (x < 0 || x > data->minfo->width)
		return (0);
	if (y < 0 || y > data->minfo->height)
		return (0);
	if (data->minfo->grid[y][x] == '1')
		return (1);
	return (0);
}

/**
 * Calculates and stores the walls texture index
 * @return: 0 if invalid texture
 * @return: 1 if valid texture
 */
static int	st_store_side(t_ray *ray)
{
	double	m_x;
	double	m_y;

	m_x = fmod(ray->pos_x, 1);
	m_y = fmod(ray->pos_y, 1);
	if (m_x > 1 - DBL_EPSILON || m_x < DBL_EPSILON)	
	{
		if (ray->vect_x >= 0)
			ray->side = WEST_TEX;
		else
			ray->side = EAST_TEX;
		return (1);
	}
	if (m_y > 1 - DBL_EPSILON || m_y < DBL_EPSILON)	
	{
		if (ray->vect_y >= 0)
			ray->side = SOUTH_TEX;
		else
			ray->side = NORTH_TEX;
		return (1);
	}
	ray->side = -1;
	return (0);
}

/**
 * Checks if the ray has collided with a wall
 * Also calculates which texure index that wall has
 * and stores that index in ray->side
 * @return: 0 if no wall
 * @return: 1 if hit wall
 */
int	collision_check(t_data *data, t_ray *ray)
{
	int		x;
	int		y;

	if (ray->vect_x < 0)
		x = (int)(ray->pos_x - DBL_EPSILON);
	else
		x = (int)(ray->pos_x);
	if (ray->vect_y < 0)
		y = (int)(ray->pos_y - DBL_EPSILON);
	else
		y = (int)(ray->pos_y);
	if (!st_wall_check(data, x, y))
		return (0);
	return (st_store_side(ray));
}
