/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:30:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 15:53:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Checks <filename>s syntax
// returns 0 if <filename> ends in FILE_FORMAT
// returns 1-3 if not
static int	st_check_name(char *filename)
{
	int	pos;

	if (filename == NULL)
		return (ERR_MAPFILE_NULL);
	if (ft_strlen(filename) < ft_strlen(FILE_FORMAT))
		return (ERR_MAPFILE_SHORT);
	pos = ft_strlen(filename) - ft_strlen(FILE_FORMAT);
	if (ft_strcmp(&(filename[pos]), FILE_FORMAT) != 0)
		return (ERR_MAPFILE_FORM);
	return (0);
}

// Check the Maps name and try to open that file
// Sets <*status> to error code
// returns -1 if any errors
// returns the opened file descriptor if success
int	mapfile_open(char *filename, int *status)
{
	int	file;

	*status = st_check_name(filename);
	if (*status != 0)
		return (-1);
	file = open(filename, O_RDONLY);
	if (file < 0)
		*status = 4;
	return (file);
}
