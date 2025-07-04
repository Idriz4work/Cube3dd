/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:54:23 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:36:20 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// for read, null and size_t
# include <unistd.h>
// for malloc
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl_line(int fd);
int		gnl_u_findc(char *string, char c);
void	gnl_u_strncpy(char **dest, char *src);
ssize_t	gnl_u_append_line(int fd, char **buffer);
void	gnl_u_remove_line(char **buffer);
void	*gnl_u_free(char **buffer);
char	*gnl_content(int fd);
int		gnl_clear(char *buffer, int fd, int retur);

#endif
