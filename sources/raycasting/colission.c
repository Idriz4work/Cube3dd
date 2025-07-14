/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colission.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:55:05 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/14 18:55:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Check collision with vertical neighbors
 * @param data: Game data
 * @param ray: Ray structure
 * @param map_x: Current x coordinate
 * @param map_y: Current y coordinate
 * @param frac_x: Fractional x position
 * @param threshold: Proximity threshold
 * @return: 1 if collision found, 0 otherwise
 */
int	st_check_vertical_neighbors(t_data *data, t_ray *ray, int map_x, int map_y)
{
	int		check_x;
	int		check_y;
	double	frac_x;

	frac_x = ray->pos_x - floor(ray->pos_x);
	if (frac_x < THRESHOLD && ray->vect_x < 0)
	{
		check_x = map_x - 1;
		check_y = map_y;
		if (wall_check(data, check_x, check_y))
		{
			ray->side = EAST_TEX;
			return (1);
		}
	}
	else if (frac_x > (1.0 - THRESHOLD) && ray->vect_x > 0)
	{
		check_x = map_x + 1;
		check_y = map_y;
		if (wall_check(data, check_x, check_y))
		{
			ray->side = WEST_TEX;
			return (1);
		}
	}
	return (0);
}

/**
 * Check collision with horizontal neighbors
 * @param data: Game data
 * @param ray: Ray structure
 * @param map_x: Current x coordinate
 * @param map_y: Current y coordinate
 * @param frac_y: Fractional y position
 * @param threshold: Proximity threshold
 * @return: 1 if collision found, 0 otherwise
 */
int	st_check_horizontal_neighbors(t_data *data, t_ray *ray, int map_x, int map_y)
{
	int		check_x;
	int		check_y;
	double	frac_y;

	frac_y = ray->pos_y - floor(ray->pos_y);
	if (frac_y < THRESHOLD && ray->vect_y < 0)
	{
		check_x = map_x;
		check_y = map_y - 1;
		if (wall_check(data, check_x, check_y))
		{
			ray->side = NORTH_TEX;
			return (1);
		}
	}
	else if (frac_y > (1.0 - THRESHOLD) && ray->vect_y > 0)
	{
		check_x = map_x;
		check_y = map_y + 1;
		if (wall_check(data, check_x, check_y))
		{
			ray->side = SOUTH_TEX;
			return (1);
		}
	}
	return (0);
}

/**
 * Main collision check function
 * @param data: Game data containing map information
 * @param ray: Ray structure to check collision for
 * @return: 0 if no wall, 1 if hit wall
 */
int	collision_check(t_data *data, t_ray *ray)
{
	int		map_x;
	int		map_y;

	map_x = (int)floor(ray->pos_x);
	map_y = (int)floor(ray->pos_y);
	if (wall_check(data, map_x, map_y))
	{
		ray->side = get_wall_side(ray);
		return (1);
	}
	if (st_check_vertical_neighbors(data, ray, map_x, map_y))
		return (1);
	if (st_check_horizontal_neighbors(data, ray, map_x, map_y))
		return (1);
	return (0);
}
