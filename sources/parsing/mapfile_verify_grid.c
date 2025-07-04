/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:27:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/26 13:27:11 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Counts and returns how many characters from the set <set>
// can be found in the <grid>
static int	st_count_set(char **grid, char *set)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	if (grid == NULL)
		return (0);
	while (grid[++i] != NULL)
	{
		j = -1;
		while (grid[i][++j] != '\0')
			if (find_cins(set, grid[i][j]) != -1)
				count++;
	}
	return (count);
}

// Flood fills <grid> to check for holes
// Starts at <x> <y>
// Counts up and returns the amount of invalid character it finds
// as well as any time the algorithm could access out of bounds
// So it returns 0 if map is properly envlosed
static int	st_flood_fill(t_map *map, char **grid, int x, int y)
{
	int	errors;

	errors = 0;
	if (x < 0 || y < 0 || x > map->width - 1 || y > map->height - 1)
		return (1);
	if (grid[y][x] == '1' || grid[y][x] == 'X')
		return (0);
	if (find_cins("NSEW0", grid[y][x]) == -1)
		return (1);
	grid[y][x] = 'X';
	errors += st_flood_fill(map, grid, x + 1, y + 1);
	errors += st_flood_fill(map, grid, x + 1, y - 1);
	errors += st_flood_fill(map, grid, x - 1, y + 1);
	errors += st_flood_fill(map, grid, x, y + 1);
	errors += st_flood_fill(map, grid, x - 1, y - 1);
	errors += st_flood_fill(map, grid, x, y - 1);
	errors += st_flood_fill(map, grid, x + 1, y);
	errors += st_flood_fill(map, grid, x - 1, y);
	return (errors);
}

// stores the coordinates of the first found player in <x> and <y>
static void	st_get_player_coords(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (map->grid[i][++j] != '\0')
			if (find_cins("NSEW", map->grid[i][j]) != -1)
				break ;
		if (find_cins("NSEW", map->grid[i][j]) != -1)
			break ;
	}
	*y = i;
	*x = j;
}

// Prepares the flood filling of the map
// Returns how many errors flood fill encounters
static int	st_prep_flooding(t_map *map)
{
	int		x;
	int		y;
	int		i;
	char	**copy;

	i = 0;
	while (map->grid[i] != NULL)
		i++;
	copy = (char **)malloc((i + 1) * sizeof(char *));
	copy[i] = NULL;
	while (--i >= 0)
		copy[i] = ft_strdup(map->grid[i]);
	st_get_player_coords(map, &x, &y);
	y = st_flood_fill(map, copy, x, y);
	i = -1;
	while (copy[++i] != NULL)
		free (copy[i]);
	free (copy);
	return (y);
}

// Checks the grid in <map> for a player, and if the map is enclosed
// Returns 12 if no player present
// Returns 13 if more then one player present
// Returns 14 if Map is not properly enclosed
int	mapfile_verify_grid(t_map *map)
{
	int	errors;

	if (st_count_set(map->grid, "NSEW") < 1)
		return (ERR_MAPGRID_PLOW);
	if (st_count_set(map->grid, "NSEW") > 1)
		return (ERR_MAPGRID_PHIGH);
	errors = st_prep_flooding(map);
	if (errors == 0)
		return (0);
	if (MAPFILE_EXT_OUT)
		printf("Map configuration errors: %i\n", errors);
	return (ERR_MAPGRID_FLOOD);
}
