/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:41:03 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 16:02:44 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s2, const char *s1)
{
	unsigned int				i;
	unsigned int				j;

	j = 0;
	i = 0;
	if (!*s1)
		return ((char*)s2);
	while (s2[i])
	{
		if (s2[i] == s1[0])
		{
			while (s1[j] != '\0' && s1[j] == s2[i + j])
				j++;
			if (s1[j] == '\0')
				return ((char*)&s2[i]);
		}
		i++;
	}
	return (0);
}
