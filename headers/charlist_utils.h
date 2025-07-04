/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:57:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/25 14:57:42 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARLIST_UTILS_H
# define CHARLIST_UTILS_H

# include <stdlib.h>

typedef struct s_charlist
{
	char				*content;
	struct s_charlist	*next;
}	t_charlist;

t_charlist	*charlist_new(char *content);
int			charlist_next(t_charlist **lst, char *content);
int			charlist_size(t_charlist **lst);
void		charlist_clear(t_charlist **lst);

#endif