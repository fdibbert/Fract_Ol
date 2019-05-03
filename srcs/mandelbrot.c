/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:42:20 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/03 22:04:58 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	m_iterate(t_mlx *p, t_com *c, t_com *z)
{
	p->n = -1;
	c->x = p->x / (p->zoom * 600) + p->move_x;
	z->x = 0;
	z->y = 0;
}

void	mandelbrot_fractal(void *parm)
{
	t_com	c;
	t_com	z;
	t_mlx	*p;
	t_com	t;

	p = (t_mlx *)parm;
	p->y = -600 + (1200 / MAX_PTHR * (p->pthr_numb - 1)) - 1;
	p->yck = 600 - 1200 / MAX_PTHR * (MAX_PTHR - p->pthr_numb);
	while (++p->y != p->yck)
	{
		c.y = p->y / (p->zoom * 600) + p->move_y;
		p->x = -601;
		while (++p->x != 600)
		{
			m_iterate(p, &c, &z);
			while ((z.x * z.x + z.y * z.y < MAX) && (++p->n < p->iter))
			{
				t = z;
				z.x = (t.x * t.x) - (t.y * t.y) + c.x;
				z.y = 2 * t.x * t.y + c.y;
			}
			if (p->n < p->iter)
				img_color(p);
		}
	}
}
