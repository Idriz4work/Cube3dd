/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:35:12 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 15:53:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Sets <map>s default values, marking non-allocated memory
void	mapfile_init(t_map *map)
{
	int	i;

	i = 0;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->grid = NULL;
	while (i < 3)
	{
		map->ceiling_color[i] = -2;
		map->floor_color[i] = -2;
		i++;
	}
	map->width = 0;
	map->height = 0;
}

// Frees all the non-NULL attributes of <map>
void	mapfile_free(t_map *map)
{
	int	i;

	i = -1;
	if (map->north_texture != NULL)
		free(map->north_texture);
	if (map->south_texture != NULL)
		free(map->south_texture);
	if (map->west_texture != NULL)
		free(map->west_texture);
	if (map->east_texture != NULL)
		free(map->east_texture);
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	if (map->grid == NULL)
		return ;
	while (map->grid[++i] != NULL)
		free(map->grid[i]);
	free(map->grid);
	map->grid = NULL;
}
