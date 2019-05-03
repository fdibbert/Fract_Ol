/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:34:22 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:23:08 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_strlengt(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t				i;
	size_t				k;
	char				*new;
	size_t				j;
	size_t				l;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlengt(s1);
	k = ft_strlengt(s2);
	j = -1;
	l = 0;
	if (!(new = malloc(sizeof(char) * (i + k + 1))))
		return (NULL);
	while (++j < i)
		new[j] = s1[j];
	while (j < (i + k))
		new[j++] = s2[l++];
	new[j] = '\0';
	return (new);
}
