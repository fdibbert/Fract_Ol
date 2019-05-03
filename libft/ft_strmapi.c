/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:11:37 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:23:38 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	char	*new;

	if (!s)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (*s)
	{
		new[size] = f(size, *(s));
		size++;
		s++;
	}
	new[size] = '\0';
	return (new);
}
