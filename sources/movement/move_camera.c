/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:20:12 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/08 18:53:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
 * Moves the camera plane and camera direction vectors to be in
 * accordance with the player and its rotation
*/
void	move_camera(t_data *data)
{
	double	d_x;
	double	d_y;

	angle_vector(&d_x, &d_y, data->rot + (double)90, \
((double)PLANE_LENGTH) / 2);
	data->plane_x = d_x;
	data->plane_y = d_y;
	angle_vector(&d_x, &d_y, data->rot, \
(((double)PLANE_LENGTH) / (double)2 * ((double)90 / (double)FOV)));
	data->dir_x = d_x;
	data->dir_y = d_y;
}
