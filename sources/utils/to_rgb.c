/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:29:04 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 16:02:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Bitshifts the int array into the pattern TTRRGGBB (hex) for the ints bits
// Returns an int for that color
// Used in converting RGB values into drawable pixel color
int	to_rgb(int r, int g, int b)
{
	return ((r % 256) << 16 | (g % 256) << 8 | (b % 256));
}
