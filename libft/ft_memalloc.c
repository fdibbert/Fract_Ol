/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:11:45 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 14:49:51 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static void	ft_bbzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n-- > 0)
	{
		*(ptr++) = 0;
	}
}

void		*ft_memalloc(size_t size)
{
	void *mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bbzero(mem, size);
	return (mem);
}
