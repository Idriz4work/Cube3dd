/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:43:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 15:44:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Takes an amount of degrees and returns the amount of radians it is
double	deg_to_rad(double degree)
{
	return (degree * (M_PI / 180.0));
}
