

__kernel void draw_fractal(__global unsigned int *buffer,
											double zoom,
											double e_x,
											double e_y,
											double move_y,
											double move_x,
											int iter,
											int num_fract,
											int color1,
											int color2,
											int color3,
											int react)
{
	unsigned int pixel;

	int		x, y, n;
	long double	zx, zy, cx, cy, tx, ty, dx;
	pixel = get_global_id(0);
	if (num_fract == 0)
	{
		y = pixel / 1200 - 600;
		x = pixel % 1200 - 600;
		n = -1;
		cy = y / (zoom * 600) + move_y;
		cx = x / (zoom * 600) + move_x;
		zx = 0.5 + e_x;
		zy = 0.5 + e_y;
		while (zx * zx + zy * zy < 4 && ++n < iter)
		{
			tx = zx - zx * zx + zy * zy;
			ty = zy - 2 * zx *zy;
			zy = cx * ty + cy * tx;
			zx = cx *tx - cy *ty;
		}
		if (n < iter && react == 0)
			buffer[pixel] = (unsigned int)((((n * color1) % 255) << 16) | (((n * color2) % 255) << 8) | (n * color3) % 255);
		if (n < iter && react == 1)
			buffer[pixel] = (unsigned int)((((n * (unsigned int)zx * 5) % 255) << 16) | (((n * (unsigned int)zy * 5) % 255) << 8) | (n * (unsigned int)cy * 5) % 255);
		if (n == iter)
			buffer[pixel] = 0;
	}
	if (num_fract == 1)
	{
		y = pixel / 1200 - 600;
		x = pixel % 1200 - 600;
		n = -1;
		zx = x / (zoom * 600) + move_x;
		zy = y / (zoom * 600) - 0.2 + move_y;
		tx = zx;
		ty = zy;
		while (tx + ty < 4 && ++n < iter)
		{
			tx = zx * zx;
			ty = zy * zy;
			zy = 2 * fabsl(zx * zy) + e_y;
			zx = tx - ty + e_x;
		}
		if (n < iter && react == 0)
			buffer[pixel] = (unsigned int)((((n * color1) % 255) << 16) | (((n * color2) % 255) << 8) | (n * color3) % 255);
		if (n < iter && react == 1)
			buffer[pixel] = (unsigned int)((((n * (unsigned int)zx * 5) % 255) << 16) | (((n * (unsigned int)zy * 5) % 255) << 8) | (n * (unsigned int)tx * 5) % 255);
		if (n == iter)
			buffer[pixel] = 0;
	}
	if (num_fract == 2)
	{
		y = pixel / 1200 - 600;
		x = pixel % 1200 - 600;
		cy = y / (zoom * 600) + move_y;
		n = -1;
		cx = x / (zoom * 600) + move_x;
		zx = 0;
		zy = 0;
		tx = zx;
		ty = zy;
		while (tx + ty < 4 && ++n < iter)
		{
			tx = zx * zx;
			ty = zy * zy;
			dx = zx;
			zx = tx - ty + cx;
			zy = 2 * dx * zy + cy;
		}
		if (n < iter && react == 0)
			buffer[pixel] = (unsigned int)((((n * color1) % 255) << 16) | (((n * color2) % 255) << 8) | (n * color3) % 255);
		if (n < iter && react == 1)
			buffer[pixel] = (unsigned int)((((n * (unsigned int)zx * 5) % 255) << 16) | (((n * (unsigned int)zy * 5) % 255) << 8) | (n * (unsigned int)cy * 5) % 255);
		if (n == iter)
			buffer[pixel] = 0;
	}
	if (num_fract == 3)
	{
		y = pixel / 1200 - 600;
		x = pixel % 1200 - 600;
		cy = y / (zoom * 600) - 0.2 + move_y;
		n = -1;
		cx = x / (zoom * 600) - 0.2 + move_x;
		zx = 0;
		zy = 0;
		tx = zx;
		ty = zy;
		while (tx + ty < 4 && ++n < iter)
		{
			tx = zx * zx;
			ty = zy * zy;
			zy = 2 * fabsl(zx * zy) + cy;
			zx = (tx - ty) + cx;
		}
		if (n < iter && react == 0)
			buffer[pixel] = (unsigned int)((((n * color1) % 255) << 16) | (((n * color2) % 255) << 8) | (n * color3) % 255);
		if (n < iter && react == 1)
			buffer[pixel] = (unsigned int)((((n * (unsigned int)zx * 5) % 255) << 16) | (((n * (unsigned int)zy * 5) % 255) << 8) | (n * (unsigned int)cy * 5) % 255);
		if (n == iter)
			buffer[pixel] = 0;
	}
	if (num_fract == 4)
	{
		y = pixel / 1200 - 600;
		x = pixel % 1200 - 600;
		n = -1;
		zx = -1 + 0.008 * ((x + 100) / zoom) + move_x;
		zy = 0.008 * (y / zoom) + move_y;
		tx = zx;
		ty = zy;
		while (++n < iter && zx * zx < 5 && zy * zy < 6)
		{
			tx = zx;
			ty = zy;
			zx = tx * (tx * tx - 3 * ty * ty);
			zy = ty * (3 * tx * tx - ty * ty);
			tx = zx;
			ty = zy;
			zx = tx * (tx * tx - 3 * ty * ty);
			zy = ty * (3 * tx * tx - ty * ty);
			zx -= 0.8 - e_x;
			zy += 0.16 + e_y;
		}
		if (n < iter && react == 0 && (fabsl(zx) < 6 || fabsl(zy) < 2.5))
		{
			buffer[pixel] = (unsigned int)((((n * color1) % 255) << 16) | (((n * color2) % 255) << 8) | (n * color3) % 255);
		}
		else if (n < iter && react == 1)
		{
			buffer[pixel] = (unsigned int)((((n * (unsigned int)zx * 5) % 255) << 16) | (((n * (unsigned int)zy * 5) % 255) << 8) | (n * (unsigned int)tx * 5) % 255);
		}
		else
			buffer[pixel] = 0;
	}
}