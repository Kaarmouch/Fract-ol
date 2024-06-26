/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:13:48 by aglampor          #+#    #+#             */
/*   Updated: 2024/06/26 15:57:19 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2)
		clean_exit(2, "Wrong arguments patern", 0);
	clean_init(&f);
	init(&f);
	get_set(&f, argv);
	ft_draw(&f);
	mlx_loop(&f.mlx);
	return (0);	
}
