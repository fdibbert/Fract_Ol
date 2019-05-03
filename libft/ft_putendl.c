/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:27:31 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:27:13 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putchar1(char c)
{
	write(1, &c, 1);
}

void		ft_putendl(char const *s)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar1(s[i]);
	ft_putchar1('\n');
}
