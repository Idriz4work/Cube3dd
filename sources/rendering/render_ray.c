/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:54:51 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/14 18:54:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Calculate the height of the wall line to be drawn
 * and determine start and end points for drawing
 */
static void	st_calc_dimensions(t_ray *ray)
{
	int	line_height;

	line_height = (int)(WINDOW_HEIGHT / (ray->wall_dist + 0.00001));
	ray->draw_start = (-line_height / 2) + (WINDOW_HEIGHT / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (line_height / 2) + (WINDOW_HEIGHT / 2);
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
	ray->wall_height = line_height;
}

/**
 * Calculate which x coordinate of the texture corresponds to the wall hit
 */
static void	st_calc_texture_x(t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == NORTH_TEX || ray->side == SOUTH_TEX)
		wall_x = ray->pos_x;
	else
		wall_x = ray->pos_y;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEXTURE_SIZE);
	if ((ray->side == NORTH_TEX || ray->side == SOUTH_TEX) && ray->vect_x > 0)
		tex_x = TEXTURE_SIZE - tex_x - 1;
	if ((ray->side == EAST_TEX || ray->side == WEST_TEX) && ray->vect_y < 0)
		tex_x = TEXTURE_SIZE - tex_x - 1;
	ray->wall_x = tex_x;
}

/**
 * Render ceiling pixels for the current column
 */
static void	st_render_ceiling(t_data *data, int x, int draw_start)
{
	int	y;
	int	color;

	color = to_rgb(data->minfo->ceiling_color[0], \
data->minfo->ceiling_color[1], \
data->minfo->ceiling_color[2]);
	y = -1;
	while (++y < draw_start)
		my_pixel_put(data->image, x, y, color);
}

/**
 * Render floor pixels for the current column
 */
static void	st_render_floor(t_data *data, int x, int draw_end)
{
	int	y;
	int	color;

	color = to_rgb(data->minfo->floor_color[0], \
data->minfo->floor_color[1], \
data->minfo->floor_color[2]);
	y = draw_end;
	while (++y < WINDOW_HEIGHT)
		my_pixel_put(data->image, x, y, color);
}

/**
 * Render a single ray column with proper textured walls
 * @param data: Game data containing textures and map info
 * @param ray: Ray information including distance, side, and wall hit position
 * @param x: Screen x coordinate for this ray column
 */
void	render_ray(t_data *data, t_ray *ray, int x)
{
	st_calc_dimensions(ray);
	st_calc_texture_x(ray);
	st_render_ceiling(data, x, ray->draw_start);
	render_wall(data, ray, x);
	st_render_floor(data, x, ray->draw_end);
}
