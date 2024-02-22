/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:35:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 01:00:35 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	calculate_win_x_y(t_vars *game)
{
	int		x;
	int		max_x; // Pour garder la trace de la longueur maximale de ligne
	int		y;

	max_x = 0;
	y = 0;
	while (game->map[y]) // Parcourir chaque ligne jusqu'à la fin du tableau
	{
		x = 0;
		while (game->map[y][x]) // Compter les colonnes dans la ligne actuelle
			x++;
		if (x > max_x) // Mettre à jour max_x si cette ligne est plus longue que les précédentes
			max_x = x;
		y++;
	}
	game->win_x = max_x; // Utiliser la longueur maximale de ligne comme win_x
	game->win_y = y; // Le nombre de lignes est win_y
}

int    ft_init(t_vars *game)
{
        game->mlx_ptr = mlx_init();
	calculate_win_x_y(game);
        game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_x * 100, game->win_y * 100, "---> FireWater <---");
	game->green_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/green.xpm", &game->green_x, &game->green_y);
	int		green_x = 0;
	int		green_y = 0;
	while (green_y <= 1000)
	{
		while (green_x <= 1500)
		{
			if (game->green_ptr != NULL)
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->green_ptr, green_x, green_y);
				green_x += 100;
			}
		}
		green_y += 100;
		green_x = 0;
	}
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_input, game);
	mlx_loop(game->mlx_ptr);
	return (EXIT_SUCCESS);
}