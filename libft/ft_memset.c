/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:56 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 14:51:19 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*pt;

	pt = (unsigned char*)ptr;
	while (num-- > 0)
		*(pt++) = (unsigned char)value;
	return (ptr);
}
