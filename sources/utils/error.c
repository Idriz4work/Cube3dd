/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:08:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/30 17:37:01 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// Prints error <message> and return <ret>
int	error(char *message, int ret)
{
	printf("Error\n");
	printf("%s\n", message);
	return (ret);
}
