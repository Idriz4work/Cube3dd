/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:14:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/08 17:08:28 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/** 
 * Angles a vector
 * @param: x_dir: x part of the vector
 * @param: y_dir; y part of the vector
 * @param: rot: the angle to turn the vector by
 * @param: distance: the length of the vector
*/
void	angle_vector(double *x_dir, double *y_dir, int rot, double distance)
{
	*x_dir = (distance * cos(deg_to_rad(rot)));
	*y_dir = (distance * sin(deg_to_rad(rot)));
	printf("Angled Vector to %.4f, %.4f, steps: %.4f, direction: %i\n", \
*x_dir, *y_dir, distance, rot);
}
