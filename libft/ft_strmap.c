/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:42:06 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:20:32 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	char	*new;

	if (!s)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (!s || !(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (*s)
	{
		new[size] = f(*(s));
		size++;
		s++;
	}
	new[size] = '\0';
	return (new);
}
