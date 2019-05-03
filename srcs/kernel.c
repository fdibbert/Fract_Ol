/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 05:16:07 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/03 22:26:30 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_properly(char *s1, int free1, char *s2, int free2)
{
	char	*temp1;
	char	*temp2;
	char	*mew;

	temp1 = s1;
	temp2 = s2;
	mew = ft_strjoin(s1, s2);
	if (free1 == 1)
		free(temp1);
	if (free2 == 1)
		free(temp2);
	return (mew);
}

static char	*read_file_with_gnl(char *file)
{
	t_gnl	gnl;

	gnl.fd = -1;
	gnl.ret = -1;
	gnl.line = NULL;
	gnl.mew = NULL;
	gnl.temp = NULL;
	if ((gnl.fd = open(file, O_RDONLY)) < 0)
		exit(0);
	while ((gnl.ret = get_next_line(gnl.fd, &gnl.line)) != 0)
	{
		gnl.line = join_properly("\n", 0, gnl.line, 1);
		if (gnl.mew != NULL)
			gnl.mew = join_properly(gnl.mew, 1, gnl.line, 1);
		else
			gnl.mew = gnl.line;
	}
	close(gnl.fd);
	return (gnl.mew);
}

static void	get_src_opencl(t_mlx *p)
{
	char	*temp;

	temp = NULL;
	temp = read_file_with_gnl("gpu.cl");
	p->opencl = temp;
}

static void	init_opencl_part_2(t_mlx *p, int *err)
{
	unsigned int	nb_pixels;

	nb_pixels = WIDTH_W * HEIGHT_W * 3;
	*err = clBuildProgram(p->program, 0, NULL, NULL, NULL, NULL);
	if (*err != CL_SUCCESS)
		exit(0);
	p->kernel = clCreateKernel(p->program, "draw_fractal", err);
	if (!p->kernel || *err != CL_SUCCESS)
		exit(0);
	if (!(p->buffer = clCreateBuffer(p->context, CL_MEM_WRITE_ONLY,
					sizeof(unsigned int) * nb_pixels, NULL, NULL)))
		exit(0);
	if ((*err = clGetKernelWorkGroupInfo(p->kernel, p->device_id,
					CL_KERNEL_WORK_GROUP_SIZE, sizeof(p->local), &p->local,
					NULL)) != CL_SUCCESS)
		exit(0);
}

void		init_opencl(t_mlx *p)
{
	int				err;

	get_src_opencl(p);
	err = -1;
	if ((err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1,
					&p->device_id, NULL)) != CL_SUCCESS)
		exit(0);
	if (!(p->context = clCreateContext(0, 1, &p->device_id, NULL, NULL, &err)))
		exit(0);
	if (!(p->commands = clCreateCommandQueue(p->context,
					p->device_id, 0, &err)))
		exit(0);
	if (!(p->program = clCreateProgramWithSource(p->context, 1,
					(const char**)&p->opencl, NULL, &err)))
		exit(0);
	init_opencl_part_2(p, &err);
}
