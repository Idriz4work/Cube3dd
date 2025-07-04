/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:26:15 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/02 16:02:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Draws the ceiling and floor colors from data->minfo on the <img>
static void	st_draw_background(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	*col;

	y = -1;
	col = data->minfo->ceiling_color;
	while (++y < WINDOW_HEIGHT / 2)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			my_pixel_put(img, x, y, to_rgb(col[0], col[1], col[2]));
	}
	y = (WINDOW_HEIGHT / 2) - 1;
	col = data->minfo->floor_color;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			my_pixel_put(img, x, y, to_rgb(col[0], col[1], col[2]));
	}
}

// Prepares an mlx image, draws on it and puts it to screen
// Stores the image object via pointer in data->image
// Old image must be freed after new one was drawn, so it needs storage
// The old data->image object gets destroyed and freed, before reasignement
// This means there will be one active image,
// that should be destroyed and freed before program termination
void	make_background(t_data *data)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return ;
	img->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
&img->line_length, &img->endian);
	st_draw_background(data, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	if (data->image != NULL)
	{
		mlx_destroy_image(data->mlx, data->image->img);
		free(data->image);
	}
	data->image = img;
}
