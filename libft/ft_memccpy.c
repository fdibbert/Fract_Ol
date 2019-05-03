/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:29:47 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:34:27 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
						int c, size_t n)
{
	size_t			i;
	unsigned char	*pt;
	unsigned char	*pt2;

	i = 0;
	pt = (unsigned char*)dst;
	pt2 = (unsigned char*)src;
	while (i < n)
	{
		pt[i] = pt2[i];
		if (pt[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
