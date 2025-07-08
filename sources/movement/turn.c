/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:39:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/08 18:02:00 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Increases and decreases angle
// 0 means upwards, increasing means turning clockwise
void	turn(t_data *data, int delta)
{
	data->rot += delta;
	if (data->rot > 360.0)
		data->rot -= 360.0;
	else if (data->rot < 0.0)
		data->rot += 360.0;
	move_camera(data);
}
