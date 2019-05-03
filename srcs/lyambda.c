/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lyambda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:42:32 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/29 10:16:24 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	l_x_start(t_mlx *p, t_com *c, t_com *z)
{
	p->n = -1;
	c->x = p->x / (p->zoom * 600) + p->move_x;
	z->x = 0.5 + p->e_x;
	z->y = 0.5 + p->e_y;
}

void	l_iterate(t_com *t, t_com *z, t_com *c)
{
	t->x = z->x - z->x * z->x + z->y * z->y;
	t->y = z->y - 2 * z->x * z->y;
	z->x = c->x * t->x - c->y * t->y;
	z->y = c->x * t->y + c->y * t->x;
}

void	img_color(t_mlx *p)
{
	int x;
	int y;

	x = p->x + 600;
	y = p->y + 600;
	if ((x <= 1199 && x >= 0) &&
		(y <= 1199 && y >= 0))
		p->imgd_pthr[x + (1200 * y)] = ((((p->n * p->color1)
			% 255) << 16) | (((p->n * p->color2) % 255) << 8)
			| (p->n * p->color3) % 255);
}

void	lyambda_fractal(void *parm)
{
	t_mlx	*p;
	t_com	c;
	t_com	z;
	t_com	t;

	p = (t_mlx *)parm;
	p->y = (-600 + (1200 / MAX_PTHR * (p->pthr_numb - 1))) - 1;
	p->yck = 600 - 1200 / MAX_PTHR * (MAX_PTHR - p->pthr_numb);
	while (++p->y != p->yck)
	{
		p->x = -601;
		c.y = p->y / (p->zoom * 600) + p->move_y;
		while (++p->x != 600)
		{
			l_x_start(p, &c, &z);
			while ((z.x * z.x + z.y * z.y < MAX) && (++p->n < p->iter))
			{
				l_iterate(&t, &z, &c);
			}
			if (p->n < p->iter)
				img_color(p);
		}
	}
}
