/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:27:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/13 15:42:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Renders the current visuals on the screen
 * @param data: Data information about the game
*/
void	render_image(t_data *data)
{
	int		i;
	t_ray	ray;

	i = -1;
	make_background(data);
	while (++i < WINDOW_WIDTH)
	{
		cast_ray(data, &ray, i);
		render_ray(data, &ray, i);
	}
	make_minimap(data);
}
