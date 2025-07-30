/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oob_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:20:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/30 15:36:29 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Checks if coordinates inside of bounds (0 - max)
 * @param x_max : - Maximum allowed x value
 * @param x_max : Maximum allowed y value
 * @param x : current x coordinate
 * @param y : current y coordinate
 * @return: 1 if out ob bounds
 * @return: 0 if inside bounds
 */
int	oob_check(double x_max, double y_max, double x, double y)
{
	if (x < 0 || x >= x_max)
		return (1);
	if (y < 0 || y >= y_max)
		return (1);
	return (0);
}
