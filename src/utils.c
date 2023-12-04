/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:30:08 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/04 04:30:54 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mouse_scroll_hook(int button, int x, int y, t_fractol *f)
{
	ptintf("Molette de la souris: bouton %d, position (%d, %d)\n", button, x, y);
	return (0);
}

int	key_press(int keycode, t_fractol *f)
{
	if (keycode == 53)
		clean_exit(0, f);
	if (keycode == 69)
	{
		f->max_r *= 0.9;
		f->min_r *= 0.9;
		f->max_i *= 0.9;
		f->min_i *= 0.9;
	}
	else if (keycode == 78)
	{
		f->max_r *= 1.1;
		f->min_r *= 1.1;
		f->max_i *= 1.1;
		f->min_i *= 1.1;
	}
	mlx_clear_window(f->mlx, f->win);
	ft_draw(f);
	return (0);
}

void	clean_exit(int exit_code, t_fractol *f)
{
	if (!f)
		exit(exit_code);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
}

int	msg(char *str1, char *str2, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (0);
}
