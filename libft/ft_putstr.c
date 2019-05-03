/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:27:23 by fdibbert          #+#    #+#             */
/*   Updated: 2018/11/27 15:26:12 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putchar1(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar1(s[i]);
}
