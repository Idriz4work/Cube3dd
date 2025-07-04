/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:32:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 15:52:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Just for debugging
// Change state of MAPFILE_EXT_OUT in laod_map.h to toggle this output
static void	st_showmap(t_map *map)
{
	int	i;

	i = -1;
	if (!MAPFILE_EXT_OUT || map == NULL)
		return ;
	printf("Map is %ix%i (width x height)\n", map->width, map->height);
	if (map->grid == NULL)
		printf("404: Map could not be found\n");
	else
		while (map->grid[++i] != NULL)
			printf("[%s]\n", map->grid[i]);
	printf("%s %s %s %s\n", map->north_texture, map->east_texture, \
map->south_texture, map->west_texture);
	printf("Floor R:%i G:%i B:%i\n", map->floor_color[0], \
map->floor_color[1], map->floor_color[2]);
	printf("Ceiling R:%i G:%i B:%i\n", map->ceiling_color[0], \
map->ceiling_color[1], map->ceiling_color[2]);
}

// Loads map into <map> object if it is working
// In case of error:
// 		Frees map object, and returns non zero value
// If nominal:
//		Returns 0
// Return values in accordance with load_map.h -> ERR_XXX_XXX
int	load_map(char *filename, t_map *map)
{
	int	status;
	int	mapfd;

	mapfile_init(map);
	mapfd = mapfile_open(filename, &status);
	if (mapfd < 0 || status != 0)
		return (status);
	status = mapfile_content(mapfd, map);
	close(mapfd);
	if (status == 0)
		status = mapfile_verify_grid(map);
	st_showmap(map);
	if (status != 0)
	{
		mapfile_free(map);
		return (status);
	}
	return (0);
}

// Notes:	Only the part of the map that is accesible by the player
//			is checked for being enclosed
//			So its possible to have parts of the map open