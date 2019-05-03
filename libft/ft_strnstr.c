/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:41:13 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 21:18:44 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s2, const char *s1, size_t n)
{
	size_t				i;
	size_t				j;

	j = 0;
	i = 0;
	if (!*s1)
		return ((char*)s2);
	while (s2[i] && i < n)
	{
		if (s2[i] == s1[0])
		{
			while (s1[j] != '\0' && s1[j] == s2[i + j] && i + j < n)
				j++;
			if (s1[j] == '\0')
				return ((char*)&s2[i]);
		}
		i++;
	}
	return (0);
}
