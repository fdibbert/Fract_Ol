/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:32:16 by fdibbert          #+#    #+#             */
/*   Updated: 2019/02/03 22:29:33 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# define A 1199
# define SIZE 6
# define LP 0.4
# define M M_PI
# define B 1200
# define MAX 4
# define MAX_PTHR 16
# define D + 600
# define WIDTH_W 1200
# define HEIGHT_W 1200
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft.h"
# include "pthread/pthread.h"
# include "mlx.h"
# include "OpenCL/cl.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"
# include "math.h"

typedef struct	s_com
{
	long double			x;
	long double			y;
}				t_com;

typedef struct	s_gnl
{
	int					fd;
	int					ret;
	char				*line;
	char				*mew;
	char				*temp;
}				t_gnl;

typedef struct	s_mlx
{
	char				*img_data;
	int					*imgd_pthr;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					key;
	int					bpp;
	int					size_line;
	int					endian;
	int					x;
	int					y;
	int					p_x;
	int					p_y;
	int					iter;
	double				e_x;
	double				e_y;
	short int			gpu;
	int					mouse_num;
	int					pthr_numb;
	unsigned int		nb_pixels;
	int					num_fract;
	int					yck;
	int					n;
	double				zoom;
	double				move_x;
	double				move_y;
	size_t				global;
	size_t				local;
	const char			*opencl;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_mem				buffer;
	cl_program			program;
	cl_kernel			kernel;
	int					color1;
	int					color2;
	int					color3;
	int					react;
}				t_mlx;

int				get_next_line(const int fd, char **line);
int				deal_mouse(int mouse, int x, int y, t_mlx *param);
int				deal_key(int key, t_mlx *param1);
void			init_opencl(t_mlx *p);
void			load_opencl(t_mlx *p);
void			img_color(t_mlx *p);
char			*ft_strsub(char const *s,
							unsigned int start, size_t len);
void			img_addr_init(t_mlx *p);
void			img_addr_del(t_mlx *p);
void			my_pthread(t_mlx *param);
void			lyambda_fractal(void *parm);
void			mandelbrot_fractal(void *parm);
void			burning_fractal(void *parm);
void			julia_fractal(void *parm);
void			my_pthread(t_mlx *param);
int				close1(void *param);
int				release_mouse (int mouse, int x, int y, t_mlx *p);
int				deal_key(int key, t_mlx *p);
void			p_restart(t_mlx *param);
void			fractal_biorob(void *parm);
int				mov_mouse(int x, int y, t_mlx *p);
void			start_mlx(t_mlx *param);

#endif
