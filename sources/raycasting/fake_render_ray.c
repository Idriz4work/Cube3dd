/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_render_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:04:29 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/08 19:19:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DISTANCE_SCALING 40
#define NORMAL_HEIGHT 4
#include "../../headers/cub3d.h"

/**
 * Displays some of the reys informaation on the screen
 * Each column of pixels is a color based on the side hit by that ray
 * Each column has a height, which indicates how far the wall is
*/
void	fake_render_ray(t_data *data, t_ray *ray)
{
	int	i;
	int	max;
	int	color;

	i = -1;
	max = NORMAL_HEIGHT + ray->wall_dist / DISTANCE_SCALING;
	color = to_rgb(0, 0, 0);
	if (ray->side == NORTH_TEX)
		color = to_rgb(255, 255, 255);
	else if (ray->side == WEST_TEX)
		color = to_rgb(255, 0, 0);
	else if (ray->side == SOUTH_TEX)
		color = to_rgb(0, 255, 0);
	else if (ray->side == EAST_TEX)
		color = to_rgb(0, 0, 255);
	while (++i < max)
	{
		mlx_pixel_put(data->mlx, data->win, ray->wall_x, WINDOW_HEIGHT - 1 - i, color);
	}
}
