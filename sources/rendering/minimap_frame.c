/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 03:58:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 03:58:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Draw a horizontal line from x, y to MMAP_SIZE, y with color
 * @param data: Data Structure
 * @param y: Y Height of the line
 * @param color: The color for the line
*/
static void st_hor_line(t_data *data, int y, int color)
{
	int	x;

	x = 0;
	while (++x < MMAP_SIZE)
		my_pixel_put(data->image, x, y, color);
}

/**
 * Draw a vertical line from x, y to MMAP_SIZE, y with color
 * @param data: Data Structure
 * @param x: X Position of the line
 * @param color: The color for the line
*/
static void st_vert_line(t_data *data, int x, int color)
{
	int	y;

	y = 0;
	while (++y < MMAP_SIZE)
		my_pixel_put(data->image, x, y, color);
}

/**
 * Draw some highlights on the frame
 */
static void st_draw_highlights(t_data *data)
{
	st_hor_line(data, (MMAP_FRAME_THICK / 2), MMAP_C_HIGHLIGHT);
	st_hor_line(data, MMAP_SIZE - 1 -(MMAP_FRAME_THICK / 2), MMAP_C_HIGHLIGHT);
	st_vert_line(data, (MMAP_FRAME_THICK / 2), MMAP_C_HIGHLIGHT);
	st_vert_line(data, MMAP_SIZE - 1 -(MMAP_FRAME_THICK / 2), MMAP_C_HIGHLIGHT);
}

/**
 * Draw the frame for the minimap
 */
void	minimap_frame(t_data *data)
{
	int	x;
	int y;

	y = -1;
	while (++y < MMAP_FRAME_THICK)
		st_hor_line(data, y, MMAP_C_CORNER);
	y = MMAP_SIZE - MMAP_FRAME_THICK - 1;
	while (++y < MMAP_SIZE)
		st_hor_line(data, y, MMAP_C_CORNER);
	x = -1;
	while (++x < MMAP_FRAME_THICK)
		st_vert_line(data, x, MMAP_C_CORNER);
	x = MMAP_SIZE - MMAP_FRAME_THICK - 1;
	while (++x < MMAP_SIZE)
		st_vert_line(data, x, MMAP_C_CORNER);
	st_draw_highlights(data);
}
