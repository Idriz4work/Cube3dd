/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:03:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/21 17:03:06 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Sets up initial angle player looks
static void	st_setup_direction(t_data *data, int x, int y)
{
	char	type;

	type = data->minfo->grid[y][x];
	if (type == 'E')
		data->rot = 0.0;
	else if (type == 'S')
		data->rot = 90.0;
	else if (type == 'W')
		data->rot = 180.0;
	else
		data->rot = 270.0;
}

// Sets up players position
static void	st_setup_player(t_data *data)
{
	int		i;
	int		j;
	char	type;

	j = -1;
	while (++j < data->minfo->height)
	{
		i = -1;
		while (++i < data->minfo->width)
		{
			type = data->minfo->grid[j][i];
			if (type == 'N' || type == 'E' || type == 'S' || type == 'W')
				break ;
		}
		if (type == 'N' || type == 'E' || type == 'S' || type == 'W')
			break ;
	}
	data->pos_x = (double)i + 0.5;
	data->pos_y = (double)j + 0.5;
	st_setup_direction(data, i, j);
	data->minfo->grid[j][i] = '0';
}

// Sets up all necessary objects, hooks and parts for the game
void	data_setup(t_data *data)
{
	setup_mlx(data);
	st_setup_player(data);
	move_camera(data);
}
