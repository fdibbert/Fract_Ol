/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biofract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:43:29 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/29 09:46:36 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		new_biorob(t_com *t, t_com *z, t_mlx *p)
{
	z->x = t->x * (t->x * t->x - 3 * t->y * t->y);
	z->y = t->y * (3 * t->x * t->x - t->y * t->y);
	t->x = z->x;
	t->y = z->y;
	z->x = t->x * (t->x * t->x - 3 * t->y * t->y);
	z->y = t->y * (3 * t->x * t->x - t->y * t->y);
	z->x -= 0.8 - p->e_x;
	z->y += 0.16 + p->e_y;
}

void		fractal_biorob(void *parm)
{
	t_mlx	*p;
	t_com	z;
	t_com	t;

	p = (t_mlx *)parm;
	p->y = -600 + (1200 / MAX_PTHR * (p->pthr_numb - 1)) - 1;
	p->yck = 600 - 1200 / MAX_PTHR * (MAX_PTHR - p->pthr_numb);
	while (++p->y != p->yck)
	{
		p->x = -600;
		while (++p->x != 600)
		{
			p->n = -1;
			z.x = -1 + 0.008 * ((p->x + 100) / p->zoom) + p->move_x;
			z.y = 0.008 * ((p->y) / p->zoom) + p->move_y;
			t = z;
			while ((z.x * z.x < 5 && z.y * z.y < 6) && (++p->n < p->iter))
			{
				t = z;
				new_biorob(&t, &z, p);
			}
			if (p->n < p->iter && (fabsl(z.x) < 6 || fabsl(z.y) < 2.5))
				img_color(p);
		}
	}
}
