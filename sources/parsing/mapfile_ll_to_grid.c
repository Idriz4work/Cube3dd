/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_ll_to_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:43:50 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:49:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Makes and returns padded copy of <source>
// Makes a string that is <length> characters long,
// by padding the end with spaces
static char	*st_strmanip(char *source, size_t length)
{
	char	*copy;
	size_t	i;

	i = -1;
	if (!source)
		return (NULL);
	if (ft_strlen(source) > length)
		length = ft_strlen(source);
	copy = (char *)malloc((length + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (++i < ft_strlen(source))
		copy[i] = source[i];
	while (i < length)
	{
		copy[i] = ' ';
		i++;
	}
	copy[length] = '\0';
	return (copy);
}

// Turns LL <lst> into 2d array for our <map>->grid
// Allocates 2d character array, frees the list
// Returns 11 of allocation failed
int	mapfile_ll_to_grid(t_charlist **lst, t_map *map)
{
	char		**new;
	int			i;
	int			length;
	t_charlist	*node;

	i = 0;
	if (lst == NULL || *lst == NULL)
		map->grid = NULL;
	node = *lst;
	length = charlist_size(lst);
	new = (char **)malloc((length + 1) * sizeof(char *));
	if (new == NULL)
		return (ERR_MAPFILE_ALOCFAIL);
	map->height = length;
	while (i < length)
	{
		new[i] = st_strmanip(node->content, map->width);
		node = node->next;
		i++;
	}
	new[length] = NULL;
	map->grid = new;
	charlist_clear(lst);
	return (0);
}
