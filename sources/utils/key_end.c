/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:24:54 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/30 17:26:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Called through hook from mlx, when X on game is pressed
int	key_end(int keycode, t_data *data)
{
	(void)keycode;
	end_game(data);
	return (0);
}
