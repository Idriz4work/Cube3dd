/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:06:37 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/14 19:09:48 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Get default color for texture when no texture is loaded
*/
static int	get_default_texture_color(int texture_id)
{
	if (texture_id == NORTH_TEX)
		return (to_rgb(193, 193, 193));
	else if (texture_id == SOUTH_TEX)
		return (to_rgb(0, 255, 0));
	else if (texture_id == EAST_TEX)
		return (to_rgb(0, 0, 255));
	else if (texture_id == WEST_TEX)
		return (to_rgb(255, 0, 0));
	return (0);
}

/**
 * Get pixel color from texture at given coordinates
 */
static int	st_get_texture_pixel(t_data *data, int x, int y, int texture_id)
{
	(void)data;
	(void)x;
	(void)y;
	return (get_default_texture_color(texture_id));
	// If textures are loaded, use this code instead:
	/*
	t_img	*texture;
	char	*pix;
	int		color;
	
	texture = (t_img *)data->text_buf[texture_id];
	if (!texture)
		return (0);
	pix = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	color = *(int *)pix;
	return (color);
	*/
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

	if (wall_dist <= 1.0)
		return (color);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	darkness = 1.0 / (1.0 + wall_dist * 0.1);
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
		color = st_get_texture_pixel(data, x, tex_y, ray->side);
		color = st_apply_dark(color, ray->wall_dist);
		my_pixel_put(data->image, x, y, color);
		tex_pos += step;
	}
}
