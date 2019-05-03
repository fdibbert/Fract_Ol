/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:40:50 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 19:18:52 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p;

	p = (0);
	while (*str)
	{
		if (*str == c)
			p = ((char*)str);
		str++;
	}
	if (p)
		return (p);
	if (c == '\0')
		return ((char*)str);
	return (0);
}
