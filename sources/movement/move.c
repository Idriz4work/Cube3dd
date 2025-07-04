/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:19:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/03 16:23:45 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

#define DEBUG_COLL 0

// Checks if at target spot there is a wall
// Returns 1 if blocked or OOB
// Returns 0 if not
// !!!TODO: Rework Bonus!!!
static int	st_check_position(t_data *data, double d_x, double d_y)
{
	if (data->pos_x + d_x < 0 || data->pos_x + d_x > data->minfo->width)
		return (1);
	if (data->pos_y + d_y < 0 || data->pos_y + d_y > data->minfo->height)
		return (1);
	if (!BONUS)
		return (0);
	if (data->minfo->grid[(int)(data->pos_y + d_y)]\
[(int)(data->pos_x + d_x)] != '0')
		return (1);
	return (0);
}

// Moves the distance <d_x> and <d_y> in small steps
static void	st_move_delta(t_data *data, double d_x, double d_y)
{
	int		i;
	double	step_x;
	double	step_y;

	i = 0;
	step_x = d_x / STEP_AMOUNT;
	step_y = d_y / STEP_AMOUNT;
	while (++i < STEP_AMOUNT + 1)
	{
		if (!st_check_position(data, step_x, 0))
			data->pos_x += step_x;
		if (!st_check_position(data, 0, step_y))
			data->pos_y += step_y;
	}
}

// Moves the player Up, down, left or right
// To be called with a DIR_X version, to move the player from rotated position
// Uses trigonometry and the law of sines to calculate difference for vector
void	move(t_data *data, int direction)
{
	double	delta_x;
	double	delta_y;
	int		amount;

	amount = 0;
	delta_x = (MOVE_SPEED * cos(deg_to_rad(data->dir - 90.0 - direction)));
	delta_y = (MOVE_SPEED * sin(deg_to_rad(data->dir - 90.0 - direction)));
	st_move_delta(data, delta_x, delta_y);
}
