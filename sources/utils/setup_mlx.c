/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:55:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/15 19:04:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/**
 * Loads image into data->tex structure, based on args
 * @param data: Data structure
 * @param tex_id: Index, like NORTH_TEXTURE, in the array
 * @param path: Path of the image to find
 */
static void	image_load(t_data *data, int tex_id, char *path)
{
	int		size;
	t_img	*img;

	data->tex[tex_id] = (t_img *)malloc(sizeof(t_img));
	img = data->tex[tex_id];
	size = TEXTURE_SIZE;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &size, &size);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
&img->line_length, &img->endian);
}

/** 
 * Creates and stores mlx images in our data structure
 * Does a second check if texture files can be converted to mlx image
 * Will STOP PROGRAM and error, if there is an issue
 * Should in theory never be called, since the first check
*/
static void	st_setup_images(t_data *data)
{
	int	i;

	image_load(data, NORTH_TEX, data->minfo->north_texture);
	image_load(data, SOUTH_TEX, data->minfo->south_texture);
	image_load(data, WEST_TEX, data->minfo->west_texture);
	image_load(data, EAST_TEX, data->minfo->east_texture);
	i = -1;
	while (++i < NUM_TEXTURES)
	{
		if (data->tex[i] == NULL)
		{
			error \
("Could not load into mlx image\n(Is texture valid xpm file?)", 0);
			end_game(data);
		}
	}
}

/**
 * Sets mlx attributes as well as hooks
*/
void	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, \
WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	data->image = NULL;
	setup_hooks(data);
	st_setup_images(data);
}
