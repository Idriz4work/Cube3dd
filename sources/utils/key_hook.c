/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:03:06 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/03 11:29:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		end_game(data);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move(data, DIR_U);
	else if (keycode == KEY_D)
		move(data, DIR_R);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move(data, DIR_D);
	else if (keycode == KEY_A)
		move(data, DIR_L);
	else if (keycode == KEY_LEFT)
		turn(data, -ROT_SPEED);
	else if (keycode == KEY_RIGHT)
		turn(data, ROT_SPEED);
	else
		printf("Key: %i\n", keycode);
	update_display(data);
	return (0);
}
