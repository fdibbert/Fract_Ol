/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:42:25 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/01 17:43:23 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	new_julia(t_com *t, t_com *z, t_mlx *p)
{
	t->x = t->x * t->x;
	t->y = t->y * t->y;
	z->y = 2 * fabsl(z->x * z->y) + p->e_y;
	z->x = (t->x - t->y) + p->e_x;
}

void	julia_fractal(void *parm)
{
	t_mlx	*p;
	t_com	z;
	t_com	t;

	p = (t_mlx *)parm;
	p->y = -600 + (1200 / MAX_PTHR * (p->pthr_numb - 1)) - 1;
	p->yck = 600 - 1200 / MAX_PTHR * (MAX_PTHR - p->pthr_numb);
	while (++p->y != p->yck)
	{
		p->x = -601;
		while (++p->x != 600)
		{
			p->n = -1;
			z.y = p->y / (p->zoom * 600) - 0.2 + p->move_y;
			z.x = p->x / (p->zoom * 600) + p->move_x;
			t = z;
			while ((t.x + t.y < MAX) && (++p->n < p->iter))
			{
				t = z;
				new_julia(&t, &z, p);
			}
			if (p->n < p->iter)
				img_color(p);
		}
	}
}
