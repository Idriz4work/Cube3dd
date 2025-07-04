/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_check_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:03:54 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 17:44:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

// Returns 1 if file could not be loaded as mlx image
// Clears all its resources always
static int	st_open_image(char *target)
{
	void	*img;
	void	*mlx;
	int		size;

	size = 1;
	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, target, &size, &size);
	if (img == NULL)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (ERR_MAPFILE_XPMIMG);
	}
	mlx_destroy_image(mlx, img);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}

// needed more lines
// Returns 6 if file cant be opened
// Returns 7 if file cant be mlx-ed
// Returns 0 otherwise
static int	st_check_texfile(char *file, char **target)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(file);
		return (ERR_MAPFILE_TEXFILE);
	}
	close(fd);
	if (st_open_image(file) != 0)
	{
		free(file);
		return (ERR_MAPFILE_XPMIMG);
	}
	*target = file;
	return (0);
}

// Tries to open the texture specified by <buffer>
// Returns 5 if error with filename
// Returns 6 if error opening file
// Returns 7 if error cause <*target> already is use
// Returns 8 if error loading mlx image
// In case of success, saves filename in <*target> and returns 0
int	mapfile_check_texture(char *buffer, char **target)
{
	int		i;
	char	*file;

	i = 2;
	if (*target != NULL)
		return (ERR_MAPFILE_DOUBLE);
	while (buffer[i] == ' ')
		i++;
	if (ft_strlen(&(buffer[i])) < 6)
		return (ERR_MAPFILE_SYNTAX);
	file = ft_strtrim(&(buffer[i]), "\n");
	return (st_check_texfile(file, target));
}
