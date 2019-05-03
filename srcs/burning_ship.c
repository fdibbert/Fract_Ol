/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:42:46 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/01 17:43:41 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	burning_iterate(t_mlx *p, t_com *z, t_com *c)
{
	p->n = -1;
	c->x = p->x / (p->zoom * 600) - 0.2 + p->move_x;
	z->x = 0;
	z->y = 0;
}

void	new_burning(t_com *t, t_com *z, t_com *c)
{
	t->x = t->x * t->x;
	t->y = t->y * t->y;
	z->y = 2 * fabsl(z->x * z->y) + c->y;
	z->x = (t->x - t->y) + c->x;
}

void	burning_fractal(void *parm)
{
	t_mlx	*p;
	t_com	c;
	t_com	z;
	t_com	t;

	p = (t_mlx *)parm;
	p->y = -600 + (1200 / MAX_PTHR * (p->pthr_numb - 1)) - 1;
	p->yck = 600 - 1200 / MAX_PTHR * (MAX_PTHR - p->pthr_numb);
	while (++p->y != p->yck)
	{
		c.y = p->y / (p->zoom * 600) - 0.2 + p->move_y;
		p->x = -601;
		while (++p->x != 600)
		{
			burning_iterate(p, &z, &c);
			t = z;
			while ((t.x + t.y < MAX) && (++p->n < p->iter))
			{
				t = z;
				new_burning(&t, &z, &c);
			}
			if (p->n < p->iter)
				img_color(p);
		}
	}
}
