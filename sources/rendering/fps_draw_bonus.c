/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:20:51 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 19:47:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Returns how many digits a positive number has
static int	st_get_digits_bonus(int num)
{
	int	len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

// Runs the function for drawing the number, based off that <num>
static void	st_trans_num_bonus(t_data *data, int num, int x, int y)
{
	if (num % 10 == 0)
		fps_0_bonus(data, x, y);
	else if (num % 10 == 1)
		fps_1_bonus(data, x, y);
	else if (num % 10 == 2)
		fps_2_bonus(data, x, y);
	else if (num % 10 == 3)
		fps_3_bonus(data, x, y);
	else if (num % 10 == 4)
		fps_4_bonus(data, x, y);
	else if (num % 10 == 5)
		fps_5_bonus(data, x, y);
	else if (num % 10 == 6)
		fps_6_bonus(data, x, y);
	else if (num % 10 == 7)
		fps_7_bonus(data, x, y);
	else if (num % 10 == 8)
		fps_8_bonus(data, x, y);
	else if (num % 10 == 9)
		fps_9_bonus(data, x, y);
}

// recursively decide which number to draw and where
static void	st_rec_draw_bonus(t_data *data, int num, int len)
{
	int	x;
	int	y;

	if (num >= 10)
		st_rec_draw_bonus(data, num / 10, len);
	x = WINDOW_WIDTH;
	y = COUNTER_Y_OFFSET;
	x -= COUNTER_X_OFFSET + COUNTER_WIDTH;
	x -= (COUNTER_SPACING + COUNTER_WIDTH) * (len - st_get_digits_bonus(num));
	if (x < 0 || x > WINDOW_WIDTH -1 || y < 0 || y > WINDOW_HEIGHT - 1)
		return ;
	st_trans_num_bonus(data, num, x, y);
}

// Draws the first line again, so the pixels of the old counter get
// removed and then draws the number of moves recursively 
void	fps_draw_bonus(t_data *data)
{
	st_rec_draw_bonus(data, data->fps, st_get_digits_bonus(data->fps));
}
