/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision_detection_helper.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:41:08 by marvin            #+#    #+#             */
/*   Updated: 2025/07/10 00:41:08 by marvin           ###   ########.fr       */
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

static int	st_wall_check(t_data *data, int x, int y)
{
	if (x < 0 || x > data->minfo->width)
		return (0);
	if (y < 0 || y > data->minfo->height)
		return (0);
	if (data->minfo->grid[y][x] == '1')
		return (1);
	return (0);
}

/**
 * Calculate fractional position within grid cell
 * @param ray: Ray structure containing position
 * @param frac_x: Pointer to store fractional x position
 * @param frac_y: Pointer to store fractional y position
 */
void st_calculate_fractional_position(t_ray *ray, double *frac_x, double *frac_y)
{
    *frac_x = ray->pos_x - floor(ray->pos_x);
    *frac_y = ray->pos_y - floor(ray->pos_y);
}

/**
 * Check if position is close to vertical grid line
 * @param frac_x: Fractional x position
 * @param threshold: Threshold for proximity check
 * @return: 1 if close to vertical line, 0 otherwise
 */
int st_is_close_to_vertical_line(double frac_x, double threshold)
{
    return (frac_x < threshold || frac_x > (1.0 - threshold));
}

/**
 * Check if position is close to horizontal grid line
 * @param frac_y: Fractional y position
 * @param threshold: Threshold for proximity check
 * @return: 1 if close to horizontal line, 0 otherwise
 */
int st_is_close_to_horizontal_line(double frac_y, double threshold)
{
    return (frac_y < threshold || frac_y > (1.0 - threshold));
}

/**
 * Determine wall side when close to vertical grid line
 * @param ray: Ray structure
 * @return: Texture index for wall side
 */
int st_get_vertical_wall_side(t_ray *ray)
{
    if (ray->vect_x > 0)
        return (WEST_TEX);
    else
        return (EAST_TEX);
}

/**
 * Determine wall side when close to horizontal grid line
 * @param ray: Ray structure
 * @return: Texture index for wall side
 */
int st_get_horizontal_wall_side(t_ray *ray)
{
    if (ray->vect_y > 0)
        return (SOUTH_TEX);
    else
        return (NORTH_TEX);
}

/**
 * Calculate distance to nearest grid lines
 * @param frac_x: Fractional x position
 * @param frac_y: Fractional y position
 * @param dist_vertical: Pointer to store vertical distance
 * @param dist_horizontal: Pointer to store horizontal distance
 */
void st_calculate_grid_distances(double frac_x, double frac_y, 
                                double *dist_vertical, double *dist_horizontal)
{
    *dist_vertical = (frac_x < 0.5) ? frac_x : (1.0 - frac_x);
    *dist_horizontal = (frac_y < 0.5) ? frac_y : (1.0 - frac_y);
}

/**
 * Determine wall side based on closest grid line
 * @param ray: Ray structure
 * @param dist_vertical: Distance to vertical grid line
 * @param dist_horizontal: Distance to horizontal grid line
 * @return: Texture index for wall side
 */
int st_determine_closest_wall_side(t_ray *ray, double dist_vertical, double dist_horizontal)
{
    if (dist_vertical < dist_horizontal)
        return st_get_vertical_wall_side(ray);
    else
        return st_get_horizontal_wall_side(ray);
}

/**
 * Main function to determine which side of the wall was hit
 * @param ray: Ray structure containing position and direction
 * @return: Texture index for the wall side
 */
int st_determine_wall_side(t_ray *ray)
{
    double frac_x, frac_y;
    double threshold = 0.0001;
    
    st_calculate_fractional_position(ray, &frac_x, &frac_y);
    
    if (st_is_close_to_vertical_line(frac_x, threshold))
        return st_get_vertical_wall_side(ray);
    
    if (st_is_close_to_horizontal_line(frac_y, threshold))
        return st_get_horizontal_wall_side(ray);
    
    double dist_vertical, dist_horizontal;
    st_calculate_grid_distances(frac_x, frac_y, &dist_vertical, &dist_horizontal);
    
    return st_determine_closest_wall_side(ray, dist_vertical, dist_horizontal);
}

/**
 * Get current grid cell coordinates
 * @param ray: Ray structure
 * @param map_x: Pointer to store x coordinate
 * @param map_y: Pointer to store y coordinate
 */
void st_get_current_cell(t_ray *ray, int *map_x, int *map_y)
{
    *map_x = (int)floor(ray->pos_x);
    *map_y = (int)floor(ray->pos_y);
}

/**
 * Check collision with current cell
 * @param data: Game data containing map information
 * @param ray: Ray structure
 * @param map_x: Current x coordinate
 * @param map_y: Current y coordinate
 * @return: 1 if collision found, 0 otherwise
 */
int st_check_current_cell(t_data *data, t_ray *ray, int map_x, int map_y)
{
    if (st_wall_check(data, map_x, map_y))
    {
        ray->side = st_determine_wall_side(ray);
        return (1);
    }
    return (0);
}

/**
 * Check collision with vertical neighbors
 * @param data: Game data
 * @param ray: Ray structure
 * @param map_x: Current x coordinate
 * @param map_y: Current y coordinate
 * @param frac_x: Fractional x position
 * @param threshold: Proximity threshold
 * @return: 1 if collision found, 0 otherwise
 */
int st_check_vertical_neighbors(t_data *data, t_ray *ray, int map_x, int map_y, 
                               double frac_x, double threshold)
{
    int check_x, check_y;
    
    if (frac_x < threshold && ray->vect_x < 0)
    {
        check_x = map_x - 1;
        check_y = map_y;
        if (st_wall_check(data, check_x, check_y))
        {
            ray->side = EAST_TEX;
            return (1);
        }
    }
    else if (frac_x > (1.0 - threshold) && ray->vect_x > 0)
    {
        check_x = map_x + 1;
        check_y = map_y;
        if (st_wall_check(data, check_x, check_y))
        {
            ray->side = WEST_TEX;
            return (1);
        }
    }
    return (0);
}

/**
 * Check collision with horizontal neighbors
 * @param data: Game data
 * @param ray: Ray structure
 * @param map_x: Current x coordinate
 * @param map_y: Current y coordinate
 * @param frac_y: Fractional y position
 * @param threshold: Proximity threshold
 * @return: 1 if collision found, 0 otherwise
 */
int st_check_horizontal_neighbors(t_data *data, t_ray *ray, int map_x, int map_y, 
                                 double frac_y, double threshold)
{
    int check_x, check_y;
    
    if (frac_y < threshold && ray->vect_y < 0)
    {
        check_x = map_x;
        check_y = map_y - 1;
        if (st_wall_check(data, check_x, check_y))
        {
            ray->side = NORTH_TEX;
            return (1);
        }
    }
    else if (frac_y > (1.0 - threshold) && ray->vect_y > 0)
    {
        check_x = map_x;
        check_y = map_y + 1;
        if (st_wall_check(data, check_x, check_y))
        {
            ray->side = SOUTH_TEX;
            return (1);
        }
    }
    return (0);
}

/**
 * Main collision check function
 * @param data: Game data containing map information
 * @param ray: Ray structure to check collision for
 * @return: 0 if no wall, 1 if hit wall
 */
int collision_check(t_data *data, t_ray *ray)
{
    int map_x, map_y;
    double frac_x, frac_y;
    double threshold = 0.0001;
    
    st_get_current_cell(ray, &map_x, &map_y);
    
    if (st_check_current_cell(data, ray, map_x, map_y))
        return (1);
    
    st_calculate_fractional_position(ray, &frac_x, &frac_y);
    
    if (st_check_vertical_neighbors(data, ray, map_x, map_y, frac_x, threshold))
        return (1);
    
    if (st_check_horizontal_neighbors(data, ray, map_x, map_y, frac_y, threshold))
        return (1);
    
    return (0);
}
