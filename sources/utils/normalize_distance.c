/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:47:34 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/28 15:48:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Normalize ray distance by its vector
 * Gets a scalar of its vector by dividing by the vector length
 * Then renormalises the scalar by multiplying it by the dir vector
 * @param data: Data structure, for dir vector
 * @param ray: Ray to be normalised
 */
void	normalize_distance(t_data *data, t_ray *ray)
{
	double	length;
	double	norm;
	double	dist;

	length = sqrt(pow(ray->vect_x, 2.0) + pow(ray->vect_y, 2.0));
	norm = ray->wall_dist / length;
	dist = (sqrt(pow(data->dir_x, 2.0) + pow(data->dir_y, 2.0)));
	ray->wall_dist = dist * norm;
}
