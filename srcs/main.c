/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:47:24 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/03 22:51:36 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define U "Usage : ./fractol [l / j / m / s / b]\n"

void		zoom(t_mlx *p, int x, int y)
{
	p->num_fract == 0 ? p->move_x += (x / 3500.0 / p->zoom) / 1.5 : 0;
	p->num_fract == 0 ? p->move_y += (y / 3500.0 / p->zoom) / 1.5 : 0;
	p->num_fract == 1 ? p->move_x += (x / 3500.0 / p->zoom) / 1.15 : 0;
	p->num_fract == 1 ? p->move_y += (y / 3500.0 / p->zoom) / 1.15 : 0;
	p->num_fract == 2 ? p->move_x += (x / 3500.0 / p->zoom) / 1.5 : 0;
	p->num_fract == 2 ? p->move_y += (y / 3500.0 / p->zoom) / 1.5 : 0;
	p->num_fract == 3 ? p->move_x += (x / 3500.0 / p->zoom) / 1.15 : 0;
	p->num_fract == 3 ? p->move_y += (y / 3500.0 / p->zoom) / 1.15 : 0;
	p->num_fract == 4 ? p->move_x += (x / 3500.0 / p->zoom) * 3.5 : 0;
	p->num_fract == 4 ? p->move_y += (y / 3500.0 / p->zoom) * 3.5 : 0;
}

int			deal_mouse(int mouse, int x, int y, t_mlx *p)
{
	if (mouse == 2)
	{
		if (p->gpu == 0)
			p->gpu = 1;
		else
			p->gpu = 0;
	}
	img_addr_init(p);
	if (mouse == 4)
	{
		p->zoom *= pow(1.05, 2);
		x = x - 600;
		y = y - 600;
		zoom(p, x, y);
	}
	if (mouse == 5)
		p->zoom /= pow(1.05, 2);
	img_addr_del(p);
	return (0);
}

int			main(int ac, char *av[])
{
	t_mlx	*p;

	p = malloc(sizeof(t_mlx));
	p->num_fract = -1;
	ac == 2 && *av[1] == 'm' && av[1][1] == '\0' ? p->num_fract = 2 : 0;
	ac == 2 && *av[1] == 's' && av[1][1] == '\0' ? p->num_fract = 3 : 0;
	ac == 2 && *av[1] == 'l' && av[1][1] == '\0' ? p->num_fract = 0 : 0;
	ac == 2 && *av[1] == 'j' && av[1][1] == '\0' ? p->num_fract = 1 : 0;
	ac == 2 && *av[1] == 'b' && av[1][1] == '\0' ? p->num_fract = 4 : 0;
	p->num_fract == -1 ? write(1, U, 39) : 0;
	p->num_fract == -1 ? exit(0) : 0;
	p->color1 = 20;
	p->color2 = 40;
	p->color3 = 30;
	p->react = 0;
	start_mlx(p);
	init_opencl(p);
	deal_mouse(0, 0, 0, p);
	mlx_hook(p->win_ptr, 4, 0, deal_mouse, p);
	mlx_hook(p->win_ptr, 6, 0, mov_mouse, p);
	mlx_hook(p->win_ptr, 17, 0, close1, p);
	mlx_hook(p->win_ptr, 2, 0, deal_key, p);
	mlx_loop(p->mlx_ptr);
}
