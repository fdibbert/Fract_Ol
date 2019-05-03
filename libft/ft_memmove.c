/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:30:10 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 14:51:14 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pt;
	unsigned char	*pt2;

	i = 0;
	pt = (unsigned char*)dst;
	pt2 = (unsigned char*)src;
	if (pt2 < pt)
	{
		while (++i <= n)
			pt[n - i] = pt2[n - i];
	}
	else
	{
		while (n-- > 0)
			*(pt++) = *(pt2++);
	}
	return (dst);
}
