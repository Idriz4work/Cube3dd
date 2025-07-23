/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:12:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/23 19:50:15 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPS_BONUS_H
# define FPS_BONUS_H

# include "cub3d.h"

// For changing the look of the counter, all values in pixels
// Colour from HEX to Decimal code converted
# define FPS_COLOR 684592
// Width of each number in the counter
# define COUNTER_WIDTH 11
// Height of each number in the counter
# define COUNTER_HEIGHT 24
// How far form the top the counter begins,
# define COUNTER_Y_OFFSET 8
// How far form the right side the counter begins,
# define COUNTER_X_OFFSET 8
// Spacing between each character
# define COUNTER_SPACING 10
// How wide each vertical line in the counter is
# define COUNTER_WIDE_DEPTH 4
// How high each horizontal line in the counter is
# define COUNTER_HIGH_DEPTH 2

// Adjusted base functions for bonus
void	fps_ver_bonus(t_data *data, int x, int y, int length);
void	fps_hor_bonus(t_data *data, int x, int y, int length);

// FPS Counter
void	fps_draw_bonus(t_data *data);
void	fps_0_bonus(t_data *data, int x, int y);
void	fps_1_bonus(t_data *data, int x, int y);
void	fps_2_bonus(t_data *data, int x, int y);
void	fps_3_bonus(t_data *data, int x, int y);
void	fps_4_bonus(t_data *data, int x, int y);
void	fps_5_bonus(t_data *data, int x, int y);
void	fps_6_bonus(t_data *data, int x, int y);
void	fps_7_bonus(t_data *data, int x, int y);
void	fps_8_bonus(t_data *data, int x, int y);
void	fps_9_bonus(t_data *data, int x, int y);

#endif