/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:31:15 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/14 19:25:12 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Determine wall side based on closest grid line
 * @param ray: Ray structure
 * @param dist_vertical: Distance to vertical grid line
 * @param dist_horizontal: Distance to horizontal grid line
 * @return: Texture index for wall side
 */
static int	st_get_closest(t_ray *ray, double frac_x, double frac_y)
{
	double	dist_vertical;
	double	dist_horizontal;

	if (frac_x < 0.5)
		dist_vertical = frac_x;
	else
		dist_vertical = 1.0 - frac_x;
	if (frac_y < 0.5)
		dist_horizontal = frac_y;
	else
		dist_horizontal = 1.0 - frac_y;
	if (dist_vertical < dist_horizontal)
	{
		if (ray->vect_x > 0)
			return (WEST_TEX);
		else
			return (EAST_TEX);
	}
	if (ray->vect_y > 0)
		return (SOUTH_TEX);
	else
		return (NORTH_TEX);
}

/**
 * Main function to determine which side of the wall was hit
 * @param ray: Ray structure containing position and direction
 * @return: Texture index for the wall side
 */
int	get_wall_side(t_ray *ray)
{
	double	frac_x;
	double	frac_y;

	frac_x = ray->pos_x - floor(ray->pos_x);
	frac_y = ray->pos_y - floor(ray->pos_y);
	if (frac_x < THRESHOLD || frac_x > (1.0 - THRESHOLD))
	{
		if (ray->vect_x > 0)
			return (WEST_TEX);
		else
			return (EAST_TEX);
	}
	if (frac_y < THRESHOLD || frac_y > (1.0 - THRESHOLD))
	{
		if (ray->vect_y > 0)
			return (SOUTH_TEX);
		else
			return (NORTH_TEX);
	}
	return (st_get_closest(ray, frac_x, frac_y));
}
