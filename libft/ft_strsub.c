/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:18:27 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:19:22 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*new;
	const unsigned char *ptr;

	if (!s)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	ptr = (unsigned char*)s;
	while (i < len)
	{
		new[i] = ptr[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
