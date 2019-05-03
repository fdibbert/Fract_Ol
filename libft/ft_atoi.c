/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:01:38 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 14:48:11 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int res;
	int neg;
	int exc;

	neg = 1;
	res = 0;
	exc = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (exc > 20 && neg == 1)
			return (-1);
		else if (exc > 20 && neg == -1)
			return (0);
		res = res * 10 + (*str - 48);
		str++;
		exc++;
	}
	return (res * neg);
}
