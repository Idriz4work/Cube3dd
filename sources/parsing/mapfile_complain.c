/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_complain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:15:10 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:27:38 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Map file opening errors
static void	st_complain_file(int type)
{
	if (type == ERR_MAPFILE_NULL)
		printf("Map file name is NULL\n(how did you even manage this?)");
	else if (type == ERR_MAPFILE_SHORT)
		printf("Map file name is too short\n(should end in %s)", FILE_FORMAT);
	else if (type == ERR_MAPFILE_FORM)
		printf("Map file format invalid\n(should end in %s)", FILE_FORMAT);
	else if (type == ERR_MAPFILE_OPEN)
		printf("Couldn\'t open map file\n(check path and permissions)");
}

// Map file content errors
static void	st_complain_content(int type)
{
	if (type == ERR_MAPFILE_SYNTAX)
		printf("Map files content has invalid syntax\n(check subject)");
	else if (type == ERR_MAPFILE_TEXFILE)
		printf("Can\'t open specified texture file\n(check path and perms)");
	else if (type == ERR_MAPFILE_XPMIMG)
		printf("Could not load into mlx image\n(Is texture valid xpm file?)");
	else if (type == ERR_MAPFILE_DOUBLE)
		printf("Attribute doubled\n(Every attribute may only occur once)");
	else if (type == ERR_MAPFILE_UNFIN)
		printf("Not all attribtues set before map\n(4 Textures, 2*3 colors)");
	else if (type == ERR_MAPFILE_INVCHAR)
		printf("Invalid character in Map\n(Only \" 01NSEW\")");
	else if (type == ERR_MAPFILE_ALOCFAIL)
		printf("Memory allocation failed\n(close some programs)");
}

// Map files map gird errpors
static void	st_complain_grid(int type)
{
	if (type == ERR_MAPGRID_PLOW)
		printf("Too few players in Map\n(At least one N, S, E or W)");
	else if (type == ERR_MAPGRID_PHIGH)
		printf("Too many players in Map\n(Only one N, S, E or W)");
	else if (type == ERR_MAPGRID_FLOOD)
		printf("Map misconfigured\n(Make sure the player is enclosed)");
}

// Gives out error messages based on <type>
void	mapfile_complain(int type)
{
	if (type == 0)
		return ;
	printf("Error\n");
	if (type < ERR_MAPFILE_NULL || type > ERR_MAPGRID_FLOOD)
		printf("!!!Unregistered Error!!!");
	st_complain_file(type);
	st_complain_content(type);
	st_complain_grid(type);
	printf("\n");
}
