/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:30:08 by aglampor          #+#    #+#             */
/*   Updated: 2024/06/26 13:43:09 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
int	ft_atoi(char *str)
{
	int	i;
	int	is_neg;
	int	res;

	is_neg = 1;
	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
}

int	key_press(int keycode, t_fractol *f)
{
	if (keycode == 53)
		clean_exit(0, "Out", f);
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

void	clean_exit(int exit_code, char *msg, t_fractol *f)
{
	if (msg != 0)
		ft_putstr_fd(msg, 2);
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
