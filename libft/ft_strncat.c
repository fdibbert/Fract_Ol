/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:40:19 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/28 19:19:19 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *restrict dst, const char *restrict app, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (app[j] != '\0' && j < n)
	{
		dst[i] = app[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
