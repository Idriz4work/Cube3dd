/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_second_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:01:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 19:47:04 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Draws a '5' at <x> <y> in the window
void	fps_5_bonus(t_data *data, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + (height / 2) - \
(COUNTER_HIGH_DEPTH / 2) + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + height - i -1, width);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + i, y, height / 2);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + (width - 1) - i, y + \
(height / 2), height / 2);
}

// Draws a '6' at <x> <y> in the window
void	fps_6_bonus(t_data *data, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + (height / 2) - \
(COUNTER_HIGH_DEPTH / 2) + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + height - i - 1, width);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + i, y, height);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + (width - 1) - i, y + \
(height / 2), height / 2);
}

// Draws a '7' at <x> <y> in the window
void	fps_7_bonus(t_data *data, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x + (width / 2), y + (height / 2) - \
(COUNTER_HIGH_DEPTH / 2) + i, (width / 2));
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + width - i -1, y, height);
}

// Draws a '8' at <x> <y> in the window
void	fps_8_bonus(t_data *data, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + (height / 2) - \
(COUNTER_HIGH_DEPTH / 2) + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + height - i -1, width);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + i, y, height);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + width - i -1, y, height);
}

// Draws a '9' at <x> <y> in the window
void	fps_9_bonus(t_data *data, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + (height / 2) - \
(COUNTER_HIGH_DEPTH / 2) + i, width);
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + height - i -1, width);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + i, y, height / 2);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + width - i -1, y, height);
}
