/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_limit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:10:38 by sikunne           #+#    #+#             */
/*   Updated: 2025/06/27 14:39:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"

// Part of ft_atoi_limit
static int	st_limit(const char *nptr, int fac, int error)
{
	long long int	temp;
	int				i;

	temp = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp = (temp * 10) + (nptr[i] - '0');
		if (temp > INT_MAX && fac == 1)
			return (error);
		if (temp - 1 > INT_MAX && fac == -1)
			return (error);
		i++;
	}
	return (temp * fac);
}

// Limited Atoi conversion
// infinite -/+, no whitespaces allowed
//		Number x has to be: min <= x <= max
// 		INT_MIN <= x <= INT_MAX
// 		nptr is not NULL
//		a number has to be there
// should any of those be invalid, returns <error>
// otherwise returns valid integer
int	atoi_limit(const char *nptr, int min, int max, int error)
{
	int	i;
	int	fac;
	int	result;

	i = 0;
	fac = 1;
	if (nptr == (void *)0)
		return (error);
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			fac = fac * -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (error);
	result = st_limit(nptr, fac, error);
	if (result < min || result > max)
		return (error);
	return (result);
}
