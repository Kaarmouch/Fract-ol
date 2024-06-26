/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:11:39 by aglampor          #+#    #+#             */
/*   Updated: 2024/06/26 15:55:22 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	get_color(int iteration, t_fractol *f) 
{
	double	red;
	double	green;
	double	blue;
	int	color;

	red = ((double)iteration * f->coef_r);
	green = ((double)iteration * f->coef_g);
	blue = ((double)iteration * f->coef_b);

	color = 0;
	color |= (int)(blue * 255);
	color |= (int)(green * 255) << 8;
	color |= (int)(red * 255) << 16;
	return (color);
}

void set_pixel_color(char *data, int x, int y, int len_b, int color) 
{
	int	pos;

	pos = y * len_b + x * 4; // Assuming 32-bit color representation (4 bytes per pixel)

	(data[pos]) = (color);
}

void	ft_draw(t_fractol *f)
{
	int	x;
	int	y;
	int	iteration;

	init_img(f);
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
			set_pixel_color(f->data, x, y, f->len_byte, get_color(iteration, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
