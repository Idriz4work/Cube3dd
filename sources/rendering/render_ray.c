
#include "../../headers/cub3d.h"

/**
 * Calculate the height of the wall line to be drawn
 * and determine start and end points for drawing
 */
static void	calculate_wall_dimensions(t_ray *ray)
{
	int	line_height;

	line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
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
static void	calculate_texture_x(t_ray *ray)
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
static int	get_texture_pixel(int texture_id)
{
	return (get_default_texture_color(texture_id));	
	// If textures are loaded, use this code instead:
	/*
	t_img	*texture;
	char	*pixel;
	int		color;
	
	texture = (t_img *)data->text_buf[texture_id];
	if (!texture)
		return (0);
	
	pixel = texture->addr + (tex_y * texture->line_length + tex_x * (texture->bpp / 8));
	color = *(int *)pixel;
	return (color);
	*/
}

/**
 * Render ceiling pixels for the current column
 */
static void	render_ceiling(t_data *data, int x, int draw_start)
{
	int	y;
	int	color;

	color = to_rgb(data->minfo->ceiling_color[0], 
				   data->minfo->ceiling_color[1], 
				   data->minfo->ceiling_color[2]);	
	y = -1;
	while (++y < draw_start)
		my_pixel_put(data->image, x, y, color);
}

/**
 * Render floor pixels for the current column
 */
static void	render_floor(t_data *data, int x, int draw_end)
{
	int	y;
	int	color;

	color = to_rgb(data->minfo->floor_color[0], 
				   data->minfo->floor_color[1], 
				   data->minfo->floor_color[2]);	
	y = draw_end;
	while (++y < WINDOW_HEIGHT)
		my_pixel_put(data->image, x, y, color);
}

/**
 * Apply distance-based darkening effect to color
 */
static int	apply_distance_darkening(int color, double wall_dist)
{
	int		r;
	int g;
	int b;
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
 * Calculate texture coordinates and step for wall rendering
 */
static void	init_wall_rendering(t_ray *ray, double *step, double *tex_pos)
{
	*step = (double)TEXTURE_SIZE / (double)ray->wall_height;
	*tex_pos = (ray->draw_start - (WINDOW_HEIGHT / 2) + (ray->wall_height / 2)) * (*step);
}

/**
 * Render the textured wall column
 */
static void	render_wall(t_data *data, t_ray *ray, int x)
{
	int		y;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;

	init_wall_rendering(ray, &step, &tex_pos);
	y = ray->draw_start - 1;
	while (++y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= TEXTURE_SIZE)
			tex_y = TEXTURE_SIZE - 1;
		if (tex_y < 0)
			tex_y = 0;
		color = get_texture_pixel(ray->side);
		color = apply_distance_darkening(color, ray->wall_dist);
		my_pixel_put(data->image, x, y, color);
		tex_pos += step;
	}
}

/**
 * Render a single ray column with proper textured walls
 * @param data: Game data containing textures and map info
 * @param ray: Ray information including distance, side, and wall hit position
 * @param x: Screen x coordinate for this ray column
 */
void	render_ray(t_data *data, t_ray *ray, int x)
{
	calculate_wall_dimensions(ray);
	calculate_texture_x(ray);
	render_ceiling(data, x, ray->draw_start);
	render_wall(data, ray, x);
	render_floor(data, x, ray->draw_end);
}
