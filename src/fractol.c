/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:13:48 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/28 19:00:01 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"

static void     get_set(t_fractol *f, char **av)
{
        if (type_cmp(av[1], "mandelbrot"))
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
        else if (type_cmp(av[1], "julia"))
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
                help_msg(f);
}

int	main(void)
{
	t_fractol	f;

	if (ac != 2)
		help_msg(&f)
	clean_init(&f)
	mlx_loop(init_ptr);
	return (0);	
}
