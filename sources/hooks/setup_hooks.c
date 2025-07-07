/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:35 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/07 15:20:46 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
Remove the pressed key from our game object
*/
static int	st_empty(int var, t_data *data)
{
	(void)var;
	data->action = 0;
	return (0);
}

/*
Store the pressed key into our game object
*/
static int	st_key_hook(int key, t_data *data)
{
	data->action = key;
	return (0);
}

/*
Set up the hooks for the mlx
*/
void	setup_hooks(t_data *data)
{
	data->action = 0;
	mlx_hook(data->win, KeyPress, KeyPressMask, st_key_hook, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, st_empty, data);
	mlx_hook(data->win, 17, 0, end_game, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}
