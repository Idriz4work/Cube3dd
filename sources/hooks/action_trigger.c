/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_trigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:10:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 17:48:30 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
Register saved action, and execute accordingly
*/
void	action_trigger(t_data *data)
{
	int	key;

	key = data->action;
	if (key == 0)
		return ;
	if (key == KEY_ESC)
		end_game(data);
	else if (key == KEY_W || key == KEY_UP)
		move(data, DIR_U);
	else if (key == KEY_D)
		move(data, DIR_R);
	else if (key == KEY_S || key == KEY_DOWN)
		move(data, DIR_D);
	else if (key == KEY_A)
		move(data, DIR_L);
	else if (key == KEY_LEFT)
		turn(data, -ROT_SPEED);
	else if (key == KEY_RIGHT)
		turn(data, ROT_SPEED);
	data->action = 0;
	return ;
}
