/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:40:49 by aglampor          #+#    #+#             */
/*   Updated: 2024/06/26 14:42:12 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int     mandelbrot(double real, double imag)
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
