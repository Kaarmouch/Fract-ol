/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:11:39 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/04 03:31:27 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mandelbrot(double real, double imag) 
{
	int iter;
	double z_real = 0.0;
	double z_imag = 0.0;
	double i_squared;
	double r_squared;

	iter = 0;
	while (iter < MAX_ITER) 
	{
		r_squared = z_real * z_real;
		i_squared = z_imag * z_imag;
		if (r_squared + i_squared > 4.0) 
			return (iter);
		z_imag = 2.0 * z_real * z_imag + imag;
		z_real = r_squared - i_squared + real;
		iter++;
	}
	return (iter);
}

int	julia(double real, double imag) 
{
	int iter;
	double c_imag;
	double c_real;
	double r_squared;
	double i_squared;

	c_imag = 0.33;
	c_real = 0.33;
	iter = 0;
	while (iter < MAX_ITER) 
	{
		r_squared = real * real;
		i_squared = imag * imag;
		if (r_squared + i_squared > 4.0)
			return (iter);
		imag = 2.0 * real * imag + c_imag;
		real = r_squared - i_squared + c_real;
		iter++;
	}
	return (iter);
}

int	get_color(int iteration, t_fractol *f) 
{
	int	color;
	int	red;
	int	green;
	int	blue;

	red = (iteration * f->coef_r) % 256;
	green = (iteration * f->coef_g) % 256;
	blue = (iteration * f->coef_b) % 256;
	color = (red << 16) | (green << 8) | blue;
	return (color);
}

void set_pixel_color(char *data, int x, int y, int len_b, int color) 
{
	int	pos;

	pos = y * len_b + x * 4; // Assuming 32-bit color representation (4 bytes per pixel)
	*(int *)(data + pos) = color;
}

void	ft_draw(t_fractol *f)
{
	int	x;
	int	y;
	int	color;
	int	iteration;

	y = 0;
	while (y < HEIGHT)
       	{
		x = 0;
		while (x < WIDTH)
		{
			f->p_r = f->min_r + (x * (f->max_r - f->min_r) / (WIDTH - 1));
			f->p_i = f->min_i + (y * (f->max_i - f->min_i) / (HEIGHT - 1));
			if (f->set == 0)
				iteration = mandelbrot(f->p_r, f->p_i);
			else if (f->set == 1)
				iteration = julia(f->p_r, f->p_i);
			color = get_color(iteration, f);
			set_pixel_color(f->data, x, y, f->len_byte, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
