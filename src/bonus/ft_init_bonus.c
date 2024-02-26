/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:35:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/26 23:54:25 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	animation(t_vars *game)
{
	static int bool = 1; // Garde l'état de l'animation entre les appels
	static struct timeval last_change = {0, 0}; // Temps du dernier changement d'état
	struct timeval current_time;
	long time_difference;

	gettimeofday(&current_time, NULL); // Obtenir le temps actuel

	// Calculer la différence de temps en microsecondes
	time_difference = (current_time.tv_sec - last_change.tv_sec) * 1000000L + (current_time.tv_usec - last_change.tv_usec);

	// Vérifier si 0,5 seconde s'est écoulée
	if (time_difference > 500000) {
		if (bool == 0) {
			set_fire_1(game);
			bool = 1;
		} else {
			set_fire_2(game);
			bool = 0;
		}
		last_change = current_time; // Mettre à jour le temps du dernier changement
	}
	return (1);
}

int	ft_init(t_vars *game)
{
	game->mlx_ptr = mlx_init();
	game->green_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/green.xpm", &game->wi, &game->he);
	game->tree_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/tree.xpm", &game->wi, &game->he);
	/*game->fire_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire.xpm", &game->wi, &game->he);*/
	game->fire_1_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire_1.xpm", &game->wi, &game->he);
	game->fire_2_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire_2.xpm", &game->wi, &game->he);
	game->water_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water.xpm", &game->wi, &game->he);
	game->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/exit.xpm", &game->wi, &game->he);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->win_x * game->wi, game->win_y * game->he, "---> FireWater <---");
	set_green(game);
	set_walls(game);
	set_fire_1(game);
	set_water(game);
	set_exit(game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_input, game);
	mlx_hook(game->win_ptr, 17, 0, &mousse_close_window, game);
	mlx_loop_hook(game->mlx_ptr, &animation, game);
	mlx_loop(game->mlx_ptr);
	return (EXIT_SUCCESS);
}
/*
set_green -->				ft_set_map.c
set_walls -->				ft_set_map.c
set_fire -->				ft_set_map.c
set_water -->				ft_set_map.c
set_exit -->				ft_set_map.c
handle_input -->			ft_hook.c
mousse_close_windows -->	ft_hook.c
*/
