/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:43:00 by aglampor          #+#    #+#             */
/*   Updated: 2024/06/26 15:36:49 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include <stdio.h>
void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->data = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->p_r = 0;
	f->p_i = 0;
	f->coef_r = 0.006;
	f->coef_g = 0.01;
	f->coef_b = 0.002;
	f->len_byte = 0;
	f->kr_j = 0.33;
	f->ki_j = 0.33;
}

void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		endian;
	char	*adr;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(1, "image creation error:", f);
	adr = mlx_get_data_addr(f->img, &pixel_bits, &f->len_byte, &endian);
	f->data = adr;
}

void     get_set(t_fractol *f, char **av)
{
	printf("%s\n",ft_tolower(av[1]));
        if (ft_strcmp(ft_tolower(av[1]), "mandelbrot"))
        {
                f->min_r = -4.0;
                f->max_r = 4.0;
                f->min_i = -4.0;
                f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
        }
        else if (ft_strcmp(ft_tolower(av[1]), "julia"))
		get_Julia(f, av);
        else
                clean_exit(2, "Wrong set name", f);
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(1, "Init bug", f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		clean_exit(1, "Init windows bug", f);
}
