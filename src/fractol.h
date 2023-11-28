/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:39:31 by aglampor          #+#    #+#             */
/*   Updated: 2023/11/28 18:16:15 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "FRACTOL_H"
# define "FRACTOL_H"

#include "../minilibx/mlx.h"

#define WIDTH 750
#define HEIGHT 750
#define MAX_ITERATIONS 100

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
}	t_fractol;

#endif
