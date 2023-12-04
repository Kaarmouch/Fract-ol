/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:13:48 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/04 04:23:37 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2)
		help_msg(&f);
	clean_init(&f);
	get_set(&f, argv);
	ft_draw(&f);
	mlx_loop(&f.mlx);
	return (0);	
}
