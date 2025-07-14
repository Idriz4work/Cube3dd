/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:13:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/14 19:14:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Calculate the perpendicular wall distance
 * @param data: Game data containing player position
 * @param ray: The ray structure with DDA results
 * @return: 1 if wall at x, y
 * @return: 0 if not, or out of range
 */

int	wall_check(t_data *data, int x, int y)
{
	if (x < 0 || x > data->minfo->width)
		return (0);
	if (y < 0 || y > data->minfo->height)
		return (0);
	if (data->minfo->grid[y][x] == '1')
		return (1);
	return (0);
}
