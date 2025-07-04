/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:40:08 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:40:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_STRUCT_H
# define IMAGE_STRUCT_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

#endif