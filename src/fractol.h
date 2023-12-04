/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:39:31 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/03 04:29:47 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "FRACTOL_H"
# define "FRACTOL_H"

#include "../minilibx/mlx.h"

#define WIDTH 750
#define HEIGHT 750
#define MAX_ITER 100

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
	double	p_r;
	double	p_i;
	int		coef_r;
	int		coef_g;
	int		coef_b;
}	t_fractol;

void	clean_init(t_fractol *f);
void	init_img(t_fractol *f);
void    get_set(t_fractol *f, char **av);
void	init(t_fractol *f);

void	help_msg(t_fractol *f);
void    get_set(t_fractol *f, char **av)


int mandelbrot(double real, double imag);
int julia(double real, double imag);
int get_color(int iteration);

void	help_msg(t_fractol *f);
int key_press(int keycode, t_fractol *f);
void	clean_exit(int exit_code, t_fractol *f);
int	msg(char *str1, char *str2, int errno);
#endif
