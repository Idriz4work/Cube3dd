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
 * Sets the rays side to the given int
 * @param ray: The ray to set
 * @param texture: Integer to set the ray->side to
 * @return: 1
 */
static int	st_set_ray(t_ray *ray, int texture)
{
	ray->side = texture;
	return (1);
}

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
static int	st_vert_next(t_data *data, t_ray *ray, int map_x, int map_y)
{
	double	frac_x;

	frac_x = ray->pos_x - floor(ray->pos_x);
	if (frac_x < THRESHOLD && ray->vect_x < 0 \
&& wall_check(data, map_x - 1, map_y))
		return (st_set_ray(ray, EAST_TEX));
	else if (frac_x > (1.0 - THRESHOLD) && ray->vect_x > 0 \
&& wall_check(data, map_x + 1, map_y))
		return (st_set_ray(ray, WEST_TEX));
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
static int	st_horiz_next(t_data *data, t_ray *ray, int map_x, int map_y)
{
	double	frac_y;

	frac_y = ray->pos_y - floor(ray->pos_y);
	if (frac_y < THRESHOLD && ray->vect_y < 0 \
&& wall_check(data, map_x, map_y - 1))
		return (st_set_ray(ray, NORTH_TEX));
	else if (frac_y > (1.0 - THRESHOLD) && ray->vect_y > 0 \
&& wall_check(data, map_x, map_y + 1))
		return (st_set_ray(ray, SOUTH_TEX));
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
	if (st_vert_next(data, ray, map_x, map_y))
		return (1);
	if (st_horiz_next(data, ray, map_x, map_y))
		return (1);
	return (0);
}
