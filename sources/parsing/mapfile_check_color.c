/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_check_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:03:54 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:47:12 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Checks if colors were set correctly
// Returns 5 in case of invalid colors, or improper ending syntax
// Returns 0 nominally
static int	st_color_verify(char *buffer, int i, int (*target)[3])
{
	if ((*target)[0] == -1 || (*target)[1] == -1 || (*target)[2] == -1)
		return (ERR_MAPFILE_SYNTAX);
	while (ft_isdigit(buffer[i]))
		i++;
	while (buffer[i] == ' ')
		i++;
	if (buffer[i] == '\n' || buffer[i] == '\0')
		return (0);
	return (ERR_MAPFILE_SYNTAX);
}

// Sets <target>s 3 values to the numbers in buffer
// Returns 5 if syntax error
// Returns 8 if colors were already set
// Returns 0 if all colors set nominally
int	mapfile_check_color(char *buffer, int (*target)[3])
{
	int	i;
	int	j;

	i = 1;
	if ((*target)[0] != -2 || (*target)[1] != -2 || (*target)[2] != -2)
		return (ERR_MAPFILE_DOUBLE);
	while (buffer[i] == ' ')
		i++;
	(*target)[0] = atoi_limit(&(buffer[i]), 0, 255, -1);
	j = 1;
	while (j < 3)
	{
		while (ft_isdigit(buffer[i]))
			i++;
		if (buffer[i] != ',')
			return (ERR_MAPFILE_SYNTAX);
		i++;
		while (buffer[i] == ' ')
			i++;
		(*target)[j] = atoi_limit(&(buffer[i]), 0, 255, -1);
		j++;
	}
	return (st_color_verify(buffer, i, target));
}
