/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:06:45 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/03 22:29:42 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		img_addr_init(t_mlx *p)
{
	if (p->gpu == 0)
	{
		p->img_ptr = mlx_new_image(p->mlx_ptr, B, B);
		p->imgd_pthr = (int *)(mlx_get_data_addr(p->img_ptr, &(p->bpp),
		&(p->size_line), &(p->endian)));
	}
	if (p->gpu == 1)
	{
		p->img_ptr = mlx_new_image(p->mlx_ptr, B, B);
		p->img_data = (mlx_get_data_addr(p->img_ptr, &(p->bpp),
		&(p->size_line), &(p->endian)));
	}
}

void		img_addr_del(t_mlx *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (p->gpu == 0)
	{
		my_pthread(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
		mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	}
	if (p->gpu == 1)
	{
		load_opencl(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
		mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	}
}

void		my_pthread(t_mlx *param)
{
	int			i;
	void		*func[5];
	t_mlx		all[MAX_PTHR];
	pthread_t	pthr[MAX_PTHR];

	i = -1;
	func[0] = lyambda_fractal;
	func[1] = julia_fractal;
	func[2] = mandelbrot_fractal;
	func[3] = burning_fractal;
	func[4] = fractal_biorob;
	while (++i < MAX_PTHR)
	{
		ft_memcpy(&all[i], param, sizeof(t_mlx));
		all[i].pthr_numb = i + 1;
		if ((pthread_create(&pthr[i], NULL,
			func[param->num_fract], (void *)&all[i])))
			exit(0);
	}
	i = -1;
	while (++i < MAX_PTHR)
		if (pthread_join(pthr[i], NULL))
			exit(0);
}

void		deal_key2(int key, t_mlx *p)
{
	key == 86 ? p->color1 += 5 : 0;
	key == 87 ? p->color2 += 5 : 0;
	key == 88 ? p->color3 += 5 : 0;
	key == 83 ? p->color1 -= 5 : 0;
	key == 84 ? p->color2 -= 5 : 0;
	key == 85 ? p->color3 -= 5 : 0;
	if (p->color1 < 0)
		p->color1 = 255;
	if (p->color2 < 0)
		p->color2 = 255;
	if (p->color3 < 0)
		p->color3 = 255;
	if (key == 71 && p->react == 1)
		key == 71 && p->react == 1 ? p->react = 0 : 0;
	else
		key == 71 && p->react == 0 ? p->react = 1 : 0;
}

int			deal_key(int key, t_mlx *p)
{
	img_addr_init(p);
	if (key == 49 && p->key == 1)
		key == 49 && p->key == 1 ? p->key = 0 : 0;
	else
		key == 49 ? p->key = 1 : 0;
	key == 4 ? p_restart(p) : 0;
	key == 126 ? p->move_y -= 0.003 * 10 / p->zoom : 0;
	key == 123 ? p->move_x += 0.003 * 10 / p->zoom : 0;
	key == 124 ? p->move_x -= 0.003 * 10 / p->zoom : 0;
	key == 125 ? p->move_y += 0.003 * 10 / p->zoom : 0;
	key == 78 ? p->iter -= 10 : 0;
	key == 69 ? p->iter += 10 : 0;
	key == 53 ? exit(0) : 0;
	key == 33 ? p->num_fract -= 1 : 0;
	key == 30 ? p->num_fract += 1 : 0;
	deal_key2(key, p);
	p->num_fract == -1 ? p->num_fract = 4 : 0;
	p->num_fract == 5 ? p->num_fract = 0 : 0;
	img_addr_del(p);
	return (0);
}
