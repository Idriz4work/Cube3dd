/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:17:49 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 13:48:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Finds character in string
// Returns the index of the first occurence of <target> in <string>
// If not there, returns -1
// Does not work for '\0'
int	find_cins(char *string, char target)
{
	int	i;

	i = 0;
	if (string == (void *)0)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == target)
			return (i);
		i++;
	}
	return (-1);
}
