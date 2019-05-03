/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stuff2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:46:55 by fdibbert          #+#    #+#             */
/*   Updated: 2019/01/29 09:50:03 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			close1(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void		p_restart(t_mlx *param)
{
	param->p_x = 0;
	param->p_y = 0;
	param->e_x = 0.0;
	param->e_y = 0.0;
	param->mouse_num = 0;
	param->key = 0;
	param->iter = 50;
	param->zoom = 1.1;
	param->move_x = 0.0;
	param->move_y = 0.0;
}

int			mov_mouse(int x, int y, t_mlx *p)
{
	img_addr_init(p);
	if (p->key == 0)
	{
		p->e_x = (x - 600) / 300.0;
		p->e_y = (y - 600) / 300.0;
		p->p_x = x;
		p->p_y = y;
	}
	img_addr_del(p);
	return (0);
}

void		start_mlx(t_mlx *param)
{
	param->p_x = 0;
	param->p_y = 0;
	param->e_x = 0.0;
	param->e_y = 0.0;
	param->mouse_num = 0;
	param->key = 0;
	param->iter = 50;
	param->pthr_numb = 1;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, B, B, "hi");
	param->zoom = 1.1;
	param->local = 0;
	param->move_x = 0.0;
	param->move_y = 0.0;
	param->opencl = NULL;
	param->device_id = NULL;
	param->gpu = 0;
	param->context = NULL;
	param->commands = NULL;
	param->buffer = NULL;
	param->program = NULL;
	param->kernel = NULL;
}
