/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:39:35 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

// gets the next line from a file desciptor, delimited by \n or EOF
char	*gnl_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	char		*ret_string;
	size_t		buff_size;

	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		buffer[0] = '\0';
	}
	bytes_read = 1;
	while (gnl_u_findc(buffer, '\n') == -1 && bytes_read > 0)
		bytes_read = gnl_u_append_line(fd, &buffer);
	if (buffer[0] == '\0' || bytes_read == -1)
		return (gnl_u_free(&buffer));
	if (gnl_u_findc(buffer, '\n') == -1)
		buff_size = gnl_u_findc(buffer, '\0');
	else
		buff_size = gnl_u_findc(buffer, '\n') + 1;
	ret_string = (char *)malloc((buff_size + 1) * sizeof(char));
	gnl_u_strncpy(&ret_string, buffer);
	gnl_u_remove_line(&buffer);
	return (ret_string);
}

// Returns NULL if nothing left in <fd> file
// Otherwise returns the first line that is not just "\n"
char	*gnl_content(int fd)
{
	char	*buffer;

	buffer = gnl_line(fd);
	if (buffer == NULL)
		return (NULL);
	while (buffer != NULL && buffer[0] == '\n')
	{
		free(buffer);
		buffer = gnl_line(fd);
		if (buffer == NULL)
			return (NULL);
	}
	return (buffer);
}

// Empties the <buffer> and gnls until file is empty.
int	gnl_clear(char *buffer, int fd, int retur)
{
	if (buffer != NULL)
		free(buffer);
	buffer = gnl_line(fd);
	while (buffer != NULL)
	{
		free(buffer);
		buffer = gnl_line(fd);
	}
	return (retur);
}
