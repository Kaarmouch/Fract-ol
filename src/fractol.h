/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:39:31 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/04 04:29:17 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx/mlx.h"
#include <stddef.h>
#include <unistd.h>

#define WIDTH 750
#define HEIGHT 750
#define MAX_ITER 100

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
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
	int		len_byte;
}	t_fractol;



void	help_msg();
char	*ft_tolower(char *str);
int	ft_strcmp(char *s1, char *s2);
void     get_set(t_fractol *f, char **av);
void	init(t_fractol *f);
void	init_img(t_fractol *f);
void	clean_init(t_fractol *f);
void	ft_draw(t_fractol *f);
void set_pixel_color(char *data, int x, int y, int len_b, int color) ;
int	get_color(int iteration, t_fractol *f);
int	julia(double real, double imag);
int	mandelbrot(double real, double imag) ;
int	mouse_scroll_hook(int button, int x, int y, t_fractol *f);
int	key_press(int keycode, t_fractol *f);
void	clean_exit(int exit_code, t_fractol *f);
int	msg(char *str1, char *str2, int errno);

#endif
