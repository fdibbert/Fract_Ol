/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:40:14 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/28 19:19:29 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict dst, const char *restrict app)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (app[j] != '\0')
	{
		dst[i] = app[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
