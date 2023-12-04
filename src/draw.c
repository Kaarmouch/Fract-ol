/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:11:39 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/03 04:44:55 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int mandelbrot(double real, double imag) 
{
	int iter;
	double z_real = 0.0;
	double z_imag = 0.0;
	double i_squared;
	double r_squared;

	iter = 0;
	for (iter < MAX_ITER) {
		r_squared = z_real * z_real;
		i_squared = z_imag * z_imag;
		// Si la magnitude carrée dépasse 4, le point est en dehors de l'ensemble
		if (r_squared + i_squared > 4.0) 
			return iter;
		// Formule de récurrence de Mandelbrot
		z_imag = 2.0 * z_real * z_imag + imag;
		z_real = r_squared - i_squared + real;
		iter++;
	}

	// Le point est probablement dans l'ensemble de Mandelbrot
	return iter;
}

int julia(double real, double imag) 
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
		// Si la magnitude carrée dépasse 4, le point est en dehors de l'ensemble
		if (r_squared + i_squared > 4.0)
			return iter;
		// Formule de récurrence de Mandelbrot
		z_imag = 2.0 * real * imag + c_imag;
		z_real = r_squared - i_squared + c_real;
		iter++;
	}
	// Le point est probablement dans l'ensemble de Mandelbrot
	return iter;
}

// Fonction pour définir la couleur en fonction du nombre d'itérations
int get_color(int iteration, t_fractol *f) 
{
    // Exemple de dégradé de couleurs : RVB (Red, Green, Blue)
    int f_adr[index + 2] = (iteration * coef_r) % 256;
    int f_adr[index + 1] = (iteration * coef_g) % 256;
    int f_adr[index] = (iteration * coef_b) % 256;

    // Combiner les canaux de couleur en une seule valeur
    int color = (red << 16) | (green << 8) | blue;

    return color;
}

void ft_draw(t_fractol *f)
{
	int	x;
	int	y;
	int	color;
	int	iteration;

	while (y = 0; y < HEIGHT; ++y)
       	{
		while (x = 0; x < WIDTH; ++x) 
		{
			f->p_r = f->x_min + (x * (f->x_max - f->x_min) / (WIDTH - 1));
			f->p_i = f->y_min + (y * (f->y_max - f->y_min) / (HEIGHT - 1));
			if(f->set == 0)
				iteration = mandelbrot(real, imag);
			else if (f->set == 1)
				iteration = juila(real,imag);

			// Obtenir la couleur en fonction du nombre d'itérations
			color = get_color(iteration);

			put_pixel(f->adr, x, y, f->len_byte, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, img_ptr, 0, 0);
}
