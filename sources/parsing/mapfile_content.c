/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:33:50 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:48:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Returns 1 if all attributes of the mapfile are stored in the object
// otherwise return 0
static int	st_is_all_set(t_map *map)
{
	if (map->north_texture == NULL || \
map->south_texture == NULL || \
map->east_texture == NULL || \
map->west_texture == NULL || \
map->ceiling_color[0] < 0 || \
map->ceiling_color[1] < 0 || \
map->ceiling_color[2] < 0 || \
map->floor_color[0] < 0 || \
map->floor_color[1] < 0 || \
map->floor_color[2] < 0)
		return (0);
	return (1);
}

// Check if the given buffer is texture instructions
// if so, store that texture information in <map>
// standard error code returning
static int	st_process_textures(char *buffer, t_map *map)
{
	if (ft_strncmp(buffer, "NO ", 3) == 0)
		return (mapfile_check_texture(buffer, &(map->north_texture)));
	if (ft_strncmp(buffer, "SO ", 3) == 0)
		return (mapfile_check_texture(buffer, &(map->south_texture)));
	if (ft_strncmp(buffer, "EA ", 3) == 0)
		return (mapfile_check_texture(buffer, &(map->east_texture)));
	if (ft_strncmp(buffer, "WE ", 3) == 0)
		return (mapfile_check_texture(buffer, &(map->west_texture)));
	if (ft_strncmp(buffer, "F ", 2) == 0)
		return (mapfile_check_color(buffer, &(map->floor_color)));
	if (ft_strncmp(buffer, "C ", 2) == 0)
		return (mapfile_check_color(buffer, &(map->ceiling_color)));
	return (ERR_MAPFILE_SYNTAX);
}

// Tries to store the line in <buffer> into the corresponding map element
// Standard parsing return scheme
static int	st_process_line(char *buffer, t_charlist **lst, t_map *map)
{
	if (buffer == NULL)
		return (ERR_MAPFILE_SYNTAX);
	if (st_is_all_set(map) == 1)
	{
		if ((lst == NULL || *lst == NULL) && ft_strcmp(buffer, "\n") == 0)
			return (0);
		return (mapfile_build_list(map, lst, buffer));
	}
	if (ft_strcmp(buffer, "\n") == 0)
		return (0);
	return (st_process_textures(buffer, map));
}

// Handles content of the Map file <mapfd>
// Prepares and verifies Colors for ceiling and floor
// as well as textures for directions
// Loads the map part of the file into a 2d array
// Returns 0 if nominal, and loaded worked
// Standard parsing return scheme
int	mapfile_content(int mapfd, t_map *map)
{
	char		*buffer;
	int			status;
	t_charlist	*lst;

	status = 0;
	lst = NULL;
	buffer = gnl_line(mapfd);
	while (status == 0 && buffer != NULL)
	{
		status = st_process_line(buffer, &lst, map);
		free(buffer);
		buffer = NULL;
		if (status == 0)
			buffer = gnl_line(mapfd);
	}
	if (status != 0)
		charlist_clear(&lst);
	else
		status = mapfile_ll_to_grid(&lst, map);
	return (gnl_clear(buffer, mapfd, status));
}
