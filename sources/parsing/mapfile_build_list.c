/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_build_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:58:14 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:47:00 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Makes a string from the map files contents
static char	*st_make_string(int length, char *source)
{
	int		i;
	char	*copy;

	i = -1;
	copy = (char *)malloc((length + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (++i < length)
		copy[i] = source[i];
	copy[i] = '\0';
	return (copy);
}

// Returns 10 if a character that isnt in VALID_MAP_CHARS is found
// Otherwise returns 0
// Sets <*length> to the length of how many characters, until only spaces left
// " 0 1        " will set lenth to 4, and return 0
static int	st_grid_line_check(char *line, int *length)
{
	int	lastpos;

	lastpos = 0;
	while (find_cins(" 01NSEW", line[lastpos]) != -1)
		lastpos++;
	if (line[lastpos] != '\n' && line[lastpos] != '\0')
		return (ERR_MAPFILE_INVCHAR);
	lastpos--;
	while (lastpos > 0 && line[lastpos] == ' ')
		lastpos--;
	if (lastpos == 0 && line[lastpos] == ' ')
		*length = 0;
	else
		*length = lastpos + 1;
	return (0);
}

// Makes a valid node for the LL <*lst> and adds it to the back
// Also updates <map>->width, if this new line is longer then the old with
// Returns 0 if every character in current node valid
// Returns 10 if invalid character found in <buffer>
int	mapfile_build_list(t_map *map, t_charlist **lst, char *buffer)
{
	int		status;
	int		length;
	char	*newline;

	length = 0;
	status = st_grid_line_check(buffer, &length);
	if (status != 0)
		return (status);
	if (map->width < length)
		map->width = length;
	newline = st_make_string(length, buffer);
	if (charlist_next(lst, newline) != 1)
		return (ERR_MAPFILE_ALOCFAIL);
	return (0);
}
