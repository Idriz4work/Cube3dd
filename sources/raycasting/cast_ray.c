/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:40:02 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/08 16:53:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/cub3d.h"

#include <stdio.h>
#include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	// For storing what the player is doing
	int		action;
	// Player position and direction
	double	pos_x;
	double	pos_y;
	double	rot;
	// Camera plane
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	// Image buffer for rendering
	int		**pixels_map;
}	t_data;

typedef struct s_ray
{
	// Ray position and direction
	double	ray_dir_x;
	double	ray_dir_y;

	// Map position
	int		map_x;
	int		map_y;
	double	d_x;
	double	d_y;

	// Delta distances
	double	delta_dist_x;
	double	delta_dist_y;

	// Side distances
	double	side_dist_x;
	double	side_dist_y;

	// Step and side
	int		step_x;
	int		step_y;
	int		side;

	// Wall distance and height
	double	wall_dist;
	int		wall_height;
	int		draw_start;
	int		draw_end;

	// Texture calculations
	double	wall_x;
	int		tex_x;
}	t_ray;

double	deg_to_rad(double degree)
{
	return (degree * (M_PI / 180.0));
}

/** 
 * Angles a vector
 * @param: x_dir: x part of the vector
 * @param: y_dir; y part of the vector
 * @param: direction: the angle to turn the vector by
 * @param: distance: the length of the vector
 * 0 degrees = -y, 90 degrees = +x, 180 degrees = +y, 270 deg = -x
*/
void	angle_vector(double *x_dir, double *y_dir, int direction, double distance)
{
	*x_dir = (distance * cos(deg_to_rad(direction)));
	*y_dir = (distance * sin(deg_to_rad(direction)));
	printf("Angled Vector to %.f, %.2f, steps: %.2f, direction: %i\n", *x_dir, *y_dir, distance, direction);
}

/*Initialise data for ray*/
static void	st_setup_ray(t_data *data, t_ray *ray, int x)
{
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->d_x = (double)data->pos_x;
	ray->d_y = (double)data->pos_y;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->wall_dist = 0;
	ray->wall_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->tex_x = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->wall_x = x;
}

#define WINDOW_WIDTH 7
#define FOV 90

/*
Get the vector for the ray
Get the factor, of how much of the plane vector needs to be added
to go from point + dir to the point of this vector on the screen

*/
static void	st_get_vector(t_data *data, t_ray *ray)
{
	double	factor;

	factor = ((ray->wall_x * 2) / (WINDOW_WIDTH - 1)) - 1;
	ray->ray_dir_x = data->dir_x + (factor * data->plane_x);
	ray->ray_dir_y = data->dir_y + (factor * data->plane_y);
	ray->d_x += ray->ray_dir_x;
	ray->d_y += ray->ray_dir_y;
	printf("Ray on: %.2f | %.2f\n", ray->d_x, ray->d_y);
	printf("Pointing in: %.2f | %.2f\n", ray->ray_dir_x, ray->ray_dir_y);
}

void	cast_ray(t_data *data, t_ray *ray, int x)
{
	st_setup_ray(data, ray, x);
	st_get_vector(data, ray);
}

// Throw out pixels for vector (pos + dir + (plane * (i/WINDOW_WIDTH /2)))
// The FOV controls the dir and the plane, and therefore this will always be fixed FOV
int	main(void)
{
	t_data data;
	t_ray	ray;
	int	i;
	int	direction;

	i = 0;
	direction = 0;
	angle_vector(&data.plane_x, &data.plane_y, direction + 90, ((double)WINDOW_WIDTH)/2);
	angle_vector(&data.dir_x, &data.dir_y, direction, (((double)WINDOW_WIDTH)/2 * (90 / (double)FOV)));
	printf("Plane: %.2f %.2f\n", data.plane_x, data.plane_y);
	printf("Dir: %.2f %.2f\n", data.dir_x, data.dir_y);
	data.pos_x = 0;
	data.pos_y = 0;
	while (i < WINDOW_WIDTH)
	{
		cast_ray(&data, &ray, i);
		i++;
	}
	return (0);
}