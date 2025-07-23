/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_hor_line_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:00:05 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 19:45:02 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Draws <length> pixels to the right, starting from <x> <y>
void	fps_hor_bonus(t_data *data, int x, int y, int length)
{
	int	i;

	i = -1;
	while (++i < length)
		my_pixel_put(data->image, x + i, y, FPS_COLOR);
}
