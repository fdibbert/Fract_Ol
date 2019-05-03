/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:10:56 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 14:50:38 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char*)dst;
	while (n-- > 0)
	{
		if (pt[i] == (unsigned char)c)
			return ((void*)(dst + i));
		i++;
	}
	return (NULL);
}
