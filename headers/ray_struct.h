/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:43:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:43:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_STRUCT_H
# define RAY_STRUCT_H

typedef struct s_ray
{
	// Ray position and direction
	double	ray_dir_x;
	double	ray_dir_y;

	// Map position
	int		map_x;
	int		map_y;

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

#endif
