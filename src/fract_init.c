/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:43:00 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/03 04:26:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->adr = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->p_r = 0;
	f->p_i = 0;
	f->coef_r = 10;
	f->coef_g = 0;
	f->coef_b = 0;
	f->len_byte = 0;
}

void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*adr;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(msg("image creation error.", "", 1), f);
	adr = mlx_get_data_addr(f->img, &pixel_bits, f->len_byte, &endian);
	f->adr = adr;
}

void     get_set(t_fractol *f, char **av)
{
        if (type_cmp(av[1], "mandelbrot"))
        {
		set = 0;
                f->min_r = -4.0;
                f->max_r = 4.0;
                f->min_i = -4.0;
                f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
        }
        else if (type_cmp(av[1], "julia"))
        {
		set = 1;
                f->min_r = -2.0;
                f->max_r = 2.0;
                f->min_i = -2.0;
                f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
        }
        else
                help_msg(f);
}


void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		clean_exit(f);
}
