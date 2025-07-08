/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:44:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/08 17:36:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	update_display(t_data *data)
{
	make_background(data);
	make_minimap(data);
	render_image(data);
}
