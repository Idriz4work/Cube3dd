/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:26:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/22 22:26:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Calculate the player offset for the current coordinates
 * Returns a value from -1 to 1, scaled up by VIEW_DISTANCE,
 * reresenting the coordinates offset from the player for that coordinate
 * @param current: coordinate from 0 to max, based on the given coordinate
 * @param max: the maximum for the coordinate system, usually MMAP_SIZE
 *  @return: Coordinate offset from player
*/
static double	st_convert(int current, int max)
{
	double	adjust;
	double	factor;

	adjust = (double)current - (double)(max / 2);
	factor = adjust / (double)max;
	return (factor * MMAP_VIEW_DISTANCE);
}

/**
 * Gets the color for the block at given coords
 * @param data: Data Structure
 * @param posx: X Position as double
 * @param posy: Y Position as double
 * @returns: Color Value for the specific tile
 */
static int	st_color_get(t_data *data, double posx, double posy)
{
	int	x;
	int	y;

	x = floor(posx);
	y = floor(posy);
	if (x < 0 || y < 0 || x > data->minfo->width - 1 || \
y > data->minfo->height - 1)
		return (0);
	if (data->minfo->grid[y][x] == '1')
		return (MMAP_C_CORNER);
	if (data->minfo->grid[y][x] == ' ')
		return (0);
	return (to_rgb(221, 194, 151));
}

/**
 * Draws the tiles around the player
 * @param data: Data Structure
 */
void	mmap_tiles_bonus(t_data *data)
{
	int		x;
	int		y;
	double	posx;
	double	posy;
	int		color;

	y = -1;
	while (++y < MMAP_SIZE)
	{
		x = -1;
		while (++x < MMAP_SIZE)
		{
			posx = data->pos_x + st_convert(x, MMAP_SIZE);
			posy = data->pos_y + st_convert(y, MMAP_SIZE);
			color = st_color_get(data, posx, posy);
			if (color != 0)
				my_pixel_put(data->image, x, y, color);
		}
	}
}
