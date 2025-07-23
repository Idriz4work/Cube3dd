/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:06:37 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 16:15:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Get pixel color from texture at given coordinates
 * @param data: Data array with the texures
 * @param x: X Coordinate of the pixel
 * @param y: Y Coordinate of the pixel
 * @param texture_id: Index of the chosen texure, like NORTH_TEXTURE
 * @return: color as integer encoded
 */
static int	st_get_texture_pixel(t_data *data, int x, int y, int texture_id)
{
	t_img	*text;
	char	*pix;
	int		color;

	text = data->tex[texture_id];
	if (!text)
		return (0);
	pix = text->addr + (y * text->line_length + x * (text->bpp / 8));
	color = *(int *)pix;
	return (color);
}

/**
 * Apply distance-based darkening effect to color
 */
static int	st_apply_dark(int color, double wall_dist)
{
	int		r;
	int		g;
	int		b;
	double	darkness;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	darkness = 1.0 / (1.0 + wall_dist * DARKNESS_INTENSITY);
	r = (int)(r * darkness);
	g = (int)(g * darkness);
	b = (int)(b * darkness);
	return (to_rgb(r, g, b));
}

/**
 * Render the textured wall column
 */
void	render_wall(t_data *data, t_ray *ray, int x)
{
	int		y;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;

	step = (double)TEXTURE_SIZE / (double)ray->wall_height;
	tex_pos = (ray->draw_start - (WINDOW_HEIGHT / 2) + \
(ray->wall_height / 2)) * (step);
	y = ray->draw_start - 1;
	while (++y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= TEXTURE_SIZE)
			tex_y = TEXTURE_SIZE - 1;
		if (tex_y < 0)
			tex_y = 0;
		color = st_get_texture_pixel(data, ray->wall_x, tex_y, ray->side);
		if (BONUS)
			color = st_apply_dark(color, ray->wall_dist);
		my_pixel_put(data->image, x, y, color);
		tex_pos += step;
	}
}
