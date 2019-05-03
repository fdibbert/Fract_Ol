/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:03:57 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/01 17:54:09 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_strlength(const char *str, int *begin,
								const unsigned char *ptr, int *len)
{
	*len = 0;
	*begin = 0;
	while (str[*len])
		*len += 1;
	while (ptr[*begin] == '\n' || ptr[*begin] == '\t'
			|| ptr[*begin] == ' ')
		*begin += 1;
}

char			*ft_strtrim(char const *s)
{
	char				*new;
	const unsigned char	*ptr;
	int					len;
	int					end;
	int					begin;

	if (!s)
		return (NULL);
	ptr = (unsigned char*)s;
	ft_strlength(s, &begin, ptr, &len);
	end = len - 1;
	while (ptr[end] == '\n' || ptr[end] == '\t' || ptr[end] == ' ')
		end--;
	end++;
	len = -1;
	if (end - begin < len)
		if (!(new = malloc(sizeof(char) * 1)))
			return (NULL);
	if (end - begin > len)
		if (!(new = malloc(sizeof(char) * ((end + 1) - begin))))
			return (NULL);
	while (begin + (++len) < end)
		new[len] = ptr[begin + len];
	new[len] = '\0';
	return (new);
}
