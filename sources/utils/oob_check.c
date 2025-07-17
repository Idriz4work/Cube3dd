/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oob_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:20:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/17 18:20:11 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Checks if coordinates inside of bounds (0 - max)
 * @params: x_max - Maximum allowed x value
 * @params: x_max - Maximum allowed y value
 * @params: x - current x coordinate
 * @params: y - current y coordinate
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
