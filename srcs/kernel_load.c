/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 06:39:36 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/03 22:25:15 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		load_arguments_opencl(t_mlx *p)
{
	int err;

	err = -1;
	err = clSetKernelArg(p->kernel, 0, sizeof(cl_mem), &p->buffer);
	err |= clSetKernelArg(p->kernel, 1, sizeof(p->zoom), &p->zoom);
	err |= clSetKernelArg(p->kernel, 2, sizeof(p->e_x), &p->e_x);
	err |= clSetKernelArg(p->kernel, 3, sizeof(p->e_y), &p->e_y);
	err |= clSetKernelArg(p->kernel, 4, sizeof(p->move_y), &p->move_y);
	err |= clSetKernelArg(p->kernel, 5, sizeof(p->move_x), &p->move_x);
	err |= clSetKernelArg(p->kernel, 6, sizeof(p->iter), &p->iter);
	err |= clSetKernelArg(p->kernel, 7, sizeof(p->num_fract), &p->num_fract);
	err |= clSetKernelArg(p->kernel, 8, sizeof(p->color1), &p->color1);
	err |= clSetKernelArg(p->kernel, 9, sizeof(p->color2), &p->color2);
	err |= clSetKernelArg(p->kernel, 10, sizeof(p->color3), &p->color3);
	err |= clSetKernelArg(p->kernel, 11, sizeof(p->react), &p->react);
	if (err != CL_SUCCESS)
		exit(0);
}

void		load_opencl(t_mlx *p)
{
	int err;

	err = -1;
	load_arguments_opencl(p);
	p->global = WIDTH_W * HEIGHT_W;
	err = clEnqueueNDRangeKernel(p->commands, p->kernel, 1, NULL,
			&p->global, &p->local, 0, NULL, NULL);
	if (err)
	{
		exit(0);
	}
	clFinish(p->commands);
	err = clEnqueueReadBuffer(p->commands, p->buffer, CL_TRUE, 0,
			sizeof(unsigned int) * p->global, p->img_data, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		exit(0);
}
