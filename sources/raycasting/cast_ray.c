/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:40:02 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/07 17:18:12 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/cub3d.h"

#define WINDOW_WIDTH 7
#include <stdio.h>

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
int	main(void)
{
	t_data data;
	t_ray	ray;
	int	i;

	i = 0;
	data.dir_x = 0;
	data.dir_y = WINDOW_WIDTH/2;
	data.plane_x = WINDOW_WIDTH/2;
	data.plane_y = 0;
	data.pos_x = 0;
	data.pos_y = 0;
	while (i < WINDOW_WIDTH)
	{
		cast_ray(&data, &ray, i);
		i++;
	}
	return (0);
}