/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:01:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:36:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	end_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (data->text_buf[i] != NULL)
			mlx_destroy_image(data->mlx, data->text_buf[i]);
	if (data->image != NULL)
	{
		mlx_destroy_image(data->mlx, data->image->img);
		free(data->image);
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	mapfile_free(data->minfo);
	exit (0);
	return (0);
}
