/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:39:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/01 17:59:03 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Increases and decreases angle
// 0 means upwards, increasing means turning clockwise
void	turn(t_data *data, int delta)
{
	data->dir += delta;
	if (data->dir > 360)
		data->dir -= 360;
	else if (data->dir < 0)
		data->dir += 360;
}
