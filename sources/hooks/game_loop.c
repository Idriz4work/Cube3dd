/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:23:01 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/07 15:02:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
Central game loop
*/
int	game_loop(t_data *data)
{
	action_trigger(data);
	update_display(data);
	return (0);
}
