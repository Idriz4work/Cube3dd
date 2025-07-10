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

/**
 * Structure containing Information for each ray in Raycasting
 */
typedef struct s_ray
{
	/**---------------
	 * For Raycasting:
	 * vect_x =			X Length of the Ray vector
	 * vect_y =			Y Lenght of the Ray vector
	 * pos_x =			Current x coordinate of the ray
	 * pos_y =			Current y coordinate of the ray
	 * */
	double	vect_x;
	double	vect_y;
	double	pos_x;
	double	pos_y;
	/**----------------
	 * For Rendering:
	 * side =			Direction the hit wall is facing
	 * wall_dist =		Distance from player to wall
	 * ray_x =			Screens X Position of this ray
	 * wall_x =			X Position where the ray hits the wall
	*/
	int		side;
	double	wall_dist;
	int		ray_x;
	int		wall_x;
	/**----------------
	 * Rendering utilities:
	 * wall_height =	Amount of pixels for the wall in the column
	 * draw_start =		Index of the first pixel of the wall
	 * draw_end =		Index of the last pixel of the wall
	 * */
	int		wall_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

#endif
