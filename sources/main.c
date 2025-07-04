/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:27:06 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/01 14:14:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	int			status;
	t_data		data;
	t_map		map;

	if (!argc_check(argc))
		return (0);
	data.minfo = &map;
	status = load_map(argv[1], &map);
	mapfile_complain(status);
	if (status != 0)
		return (0);
	data_setup(&data);
	mlx_loop(data.mlx);
	return (0);
}
