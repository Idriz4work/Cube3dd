/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_first_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:01:47 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 19:46:51 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Draws a '0' at <x> <y> in the window
void	fps_0_bonus(t_data *data, int x, int y)
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
		fps_hor_bonus(data, x, y + height - i -1, width);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + i, y, height);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + width - i -1, y, height);
}

// Draws a '1' at <x> <y> in the window
void	fps_1_bonus(t_data *data, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH / 2;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x + width, y + i, width);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + (width * 2) - i -1, y, height);
}

// Draws a '2' at <x> <y> in the window
void	fps_2_bonus(t_data *data, int x, int y)
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
		fps_ver_bonus(data, x + (width - 1) - i, y, height / 2);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + i, y + (height / 2), height / 2);
}

// Draws a '3' at <x> <y> in the window
void	fps_3_bonus(t_data *data, int x, int y)
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
		fps_ver_bonus(data, x + (width -1) - i, y, height);
}

// Draws a '4' at <x> <y> in the window
void	fps_4_bonus(t_data *data, int x, int y)
{
	int	i;
	int	height;
	int	width;

	height = COUNTER_HEIGHT;
	width = COUNTER_WIDTH;
	i = -1;
	while (++i < COUNTER_HIGH_DEPTH)
		fps_hor_bonus(data, x, y + (height / 2) - \
(COUNTER_HIGH_DEPTH / 2) + i, width);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + (width) - i -1, y, height);
	i = -1;
	while (++i < COUNTER_WIDE_DEPTH)
		fps_ver_bonus(data, x + i, y, height / 2);
}
