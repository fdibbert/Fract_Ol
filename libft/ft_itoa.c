/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:59:13 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 14:48:58 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_start(unsigned int *i, int *j, int *n, int *d)
{
	*j = 1;
	*d = 0;
	if (*n < 0)
	{
		*j = *j + 1;
		*n = *n * (-1);
		*d = 1;
	}
	*i = *n;
}

char			*ft_itoa(int n)
{
	unsigned int	i;
	int				j;
	char			*c;
	int				d;

	ft_start(&i, &j, &n, &d);
	while (i > 9)
	{
		i = i / 10;
		j++;
	}
	if (!(c = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	c[j--] = '\0';
	i = n;
	while (i > 9)
	{
		c[j--] = (i % 10) + '0';
		i = i / 10;
	}
	c[j] = i + '0';
	if (d == 1)
		c[--j] = '-';
	return (c);
}
