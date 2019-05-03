/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:11:10 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:20:07 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*c;

	i = 0;
	if (!(c = malloc(size + 1)))
		return (NULL);
	while (i < (size + 1))
	{
		c[i] = '\0';
		i++;
	}
	return (c);
}
