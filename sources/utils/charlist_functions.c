/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charlist_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:17:57 by iatilla-          #+#    #+#             */
/*   Updated: 2025/06/27 14:34:50 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/charlist_utils.h"

// Add the heap allocated string <content> to a new linked list element
// Freeing the string should be done by the linked list
// Returns a pointer to our new list element
t_charlist	*charlist_new(char *content)
{
	t_charlist	*s;

	s = (t_charlist *)malloc(sizeof(t_charlist));
	if (!s)
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}

// Adds the heap allocated string <content> to the end of our LL
// by adding a new heap allocated element
// Returns 0 if allocation failed
// Returns 1 if nominal execution
int	charlist_next(t_charlist **lst, char *content)
{
	t_charlist	*current;

	if (lst == NULL)
		return (0);
	if (*lst == NULL)
	{
		*lst = charlist_new(content);
		if (*lst == NULL)
			return (0);
		return (1);
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = charlist_new(content);
	if (current->next == NULL)
		return (0);
	return (1);
}

// Returns the length of the LL <*lst>
int	charlist_size(t_charlist **lst)
{
	int			i;
	t_charlist	*node;

	i = 0;
	if (lst == NULL || *lst == NULL)
		return (0);
	node = *lst;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

// Frees all elements of our LL <lst>, and its content strings
// Then sets <*lst> to NULL
void	charlist_clear(t_charlist **lst)
{
	t_charlist	*current;
	t_charlist	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		if (current->content != NULL)
			free(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
