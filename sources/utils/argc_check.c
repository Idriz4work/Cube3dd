/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:06:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/30 17:36:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// For veryfing right argument count
// If value is exactly 2, returns 1
// Otherwise, prints error and returns 0
int	argc_check(int argc)
{
	if (argc < 2)
		return (error("No Arguments\n(Please provide a map file", 0));
	if (argc > 2)
		return (error("Too many Arguments\n(Please provide 1 map file", 0));
	return (1);
}
