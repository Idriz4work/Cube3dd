/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:03:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 18:00:31 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Sets up initial angle player looks
static void	st_setup_direction(t_data *data, int x, int y)
{
	char	type;

	type = data->minfo->grid[y][x];
	if (type == 'E')
		data->dir = 90;
	else if (type == 'S')
		data->dir = 180;
	else if (type == 'W')
		data->dir = 270;
	else
		data->dir = 0;
}

// Sets up players position
static void	st_setup_player(t_data *data)
{
	int		i;
	int		j;
	char	type;

	j = -1;
	while (++j < data->minfo->height)
	{
		i = -1;
		while (++i < data->minfo->width)
		{
			type = data->minfo->grid[j][i];
			if (type == 'N' || type == 'E' || type == 'S' || type == 'W')
				break ;
		}
		if (type == 'N' || type == 'E' || type == 'S' || type == 'W')
			break ;
	}
	data->pos_x = i;
	data->pos_y = j;
	st_setup_direction(data, i, j);
	data->minfo->grid[j][i] = '0';
}

// Sets mlx attributes as well as hooks
static void	st_setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, \
WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	data->image = NULL;
	mlx_hook(data->win, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(data->win, 17, 0, end_game, data);
}

// Creates and stores mlx images in our data structure
// Does a second check if texture files can be converted to mlx image
// Will STOP PROGRAM and error, if there is an issue
// Should in theory never be called, since the first check
static void	st_setup_images(t_data *data)
{
	int	size;

	size = TEXTURE_SIZE;
	data->text_buf[NORTH_TEX] = mlx_xpm_file_to_image(data->mlx, \
data->minfo->north_texture, &size, &size);
	data->text_buf[SOUTH_TEX] = mlx_xpm_file_to_image(data->mlx, \
data->minfo->south_texture, &size, &size);
	data->text_buf[WEST_TEX] = mlx_xpm_file_to_image(data->mlx, \
data->minfo->west_texture, &size, &size);
	data->text_buf[EAST_TEX] = mlx_xpm_file_to_image(data->mlx, \
data->minfo->east_texture, &size, &size);
	size = -1;
	while (++size < NUM_TEXTURES)
	{
		if (data->text_buf[size] == NULL)
		{
			error \
("Could not load into mlx image\n(Is texture valid xpm file?)", 0);
			end_game(data);
		}
	}
}

// Sets up all necessary objects, hooks and parts for the game
void	data_setup(t_data *data)
{
	st_setup_mlx(data);
	st_setup_player(data);
	st_setup_images(data);
}
