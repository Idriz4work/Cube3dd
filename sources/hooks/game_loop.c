/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:23:01 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/30 16:15:23 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	st_fps(t_data *data)
{
	struct timeval	timestamp;

	if (!BONUS)
		return ;
	data->frame++;
	gettimeofday(&timestamp, NULL);
	if (timestamp.tv_sec != data->oldtime)
	{
		data->fps = data->frame;
		data->frame = 0;
		data->oldtime = timestamp.tv_sec;
	}
	fps_draw_bonus(data);
}

/**
 * Central game loop
 * we move the player based on the keybinds (input) calling action_trigger
 * we then update the window calling render_image
 * we calculate the fps last in st_fps
 * @param data: central data strcuture for the entire game
 * @return 0 for success
*/
int	game_loop(t_data *data)
{
	action_trigger(data);
	render_image(data);
	st_fps(data);
	return (0);
}
