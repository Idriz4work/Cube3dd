/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:59:28 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:39:30 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

// return index of first occurence of character c..
// ..in string string, or -1 if not found
int	gnl_u_findc(char *string, char c)
{
	int	i;

	i = 0;
	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	if (string[i] == c)
		return (i);
	return (-1);
}

// copy from src to dest until you hit a \n or a \0
void	gnl_u_strncpy(char **dest, char *src)
{
	size_t	i;

	i = 0;
	if ((*dest) == NULL || src == NULL)
		return ;
	while (src[i] != '\0' && src[i] != '\n')
	{
		(*dest)[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
}

// Appends a new line from a file to the given buffer by reallocation
// assigns a new array big enough to handle the current content and the new line
// copy the old array into the new one, then add the new line,..
// ..starting at the '\0'
// add the '\0' to the end to terminate properly and mark end
// switch buffer to new_buffer and free the old buffer
ssize_t	gnl_u_append_line(int fd, char **buffer)
{
	ssize_t	bytes_read;
	size_t	curr_len;
	char	*new_buffer;

	bytes_read = 0;
	curr_len = 0;
	while ((*buffer)[curr_len] != '\0')
		curr_len++;
	new_buffer = (char *)malloc(curr_len + BUFFER_SIZE + 1);
	while ((*buffer)[bytes_read] != '\0')
	{
		new_buffer[bytes_read] = (*buffer)[bytes_read];
		bytes_read++;
	}
	bytes_read = read(fd, new_buffer + curr_len, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(new_buffer);
		new_buffer = NULL;
		return (bytes_read);
	}
	new_buffer[curr_len + bytes_read] = '\0';
	free(*buffer);
	(*buffer) = new_buffer;
	return (bytes_read);
}

// remove the first substring delimited by a \n from buffer by reallocation
// count up so start is index of \n 
// then move until the end of buffer
// allocate enough space for rest of str, then assign that rest to new_buffer
// if no \n is found, buffer[0] is set to '\0'
void	gnl_u_remove_line(char **buffer)
{
	int		i;
	int		start;
	char	*new_buffer;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	start = i + 1;
	while ((*buffer)[i] != '\0')
		i++;
	if (i < start)
		start = i;
	new_buffer = (char *)malloc(((i - start) + 1) * sizeof(char));
	i = 0;
	while ((*buffer)[start] != '\0')
	{
		new_buffer[i] = (*buffer)[start];
		i++;
		start++;
	}
	new_buffer[i] = '\0';
	free(*buffer);
	*buffer = new_buffer;
}

// frees the buffer and returns NULL
void	*gnl_u_free(char **buffer)
{
	free((*buffer));
	*buffer = NULL;
	return (NULL);
}
