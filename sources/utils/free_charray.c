/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_charray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:59:06 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 16:05:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Frees <array>s char arrays
void	free_charray(char **array)
{
	int	i;

	i = -1;
	if (array == NULL)
		return ;
	while (array[++i] != NULL)
		free(array[i]);
	array = NULL;
}
