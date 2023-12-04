/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:30:08 by aglampor          #+#    #+#             */
/*   Updated: 2023/12/03 03:26:59 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int mouse_scroll_hook(int button, int x, int y, t_fractol *f)
{
    // Affiche les informations sur la molette
	ptintf("Molette de la souris: bouton %d, position (%d, %d)\n", button, x, y);
		
    // Vous pouvez appeler votre fonction ici
    // Exemple : votre_fonction();

	return (0);
}

// Fonction de gestion des événements de clavier
int key_press(int keycode, t_fractol *f) 
{
	if (keycode == 53) // Touche Escape (quitter)
		clean_exit(0, f);
	if (keycode == 69) 
	{ // Touche +
		f->x_max *= 0.9;
		f->x_min *= 0.9;
		f->y_max *= 0.9;
		f->y_min *= 0.9;
	} 
	else if (keycode == 78) 
	{ // Touche -
		f->x_max *= 1.1;
		f->x_min *= 1.1;
		f->y_max *= 1.1;
		f->y_min *= 1.1;
	}

	// Effacer la fenêtre avant de redessiner
	mlx_clear_window(data->mlx, data->win);

	// Redessiner l'ensemble avec les nouvelles limites
	ft_draw(data);

	return 0;
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
