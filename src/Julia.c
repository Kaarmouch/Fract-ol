/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:59:39 by aglampor          #+#    #+#             */
/*   Updated: 2024/06/26 15:13:13 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void     get_Julia(t_fractol *f, char **av)
{
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;

	if (av[2])
	{
		f->kr_j = ft_atoi(av[2]);
		if (av[3])
			f->ki_j = ft_atoi(av[3]);
		else
			f->ki_j = ft_atoi(av[2]);
	}
	if (f->kr_j < -2 || f->kr_j > 2 || f->ki_j < -2 || f->ki_j > 2)
		clean_exit(2, "Wrong Julia info passed", f);
}

int     julia(double real, double imag)
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
