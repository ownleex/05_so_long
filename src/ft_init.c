/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:35:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 16:38:12 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_init(t_vars *game)
{
	game->mlx_ptr = mlx_init();
	game->green_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/green.xpm", &game->wi, &game->he);
	game->tree_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/tree.xpm", &game->wi, &game->he);
	game->fire_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire.xpm", &game->wi, &game->he);
	game->water_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water.xpm", &game->wi, &game->he);
	game->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/exit.xpm", &game->wi, &game->he);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->win_x * game->wi, game->win_y * game->he, "---> FireWater <---");
	set_green(game);
	set_walls(game);
	set_fire(game);
	set_water(game);
	set_exit(game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_input, game);
	mlx_hook(game->win_ptr, 17, 0, &mousse_close_window, game);
	mlx_loop(game->mlx_ptr);
	return (EXIT_SUCCESS);
}
/*
[1]
set_green -->					[1] ft_set_map.c
set_walls -->					[2] ft_set_map.c
set_fire -->					[4] ft_set_map.c
set_water -->					[3] ft_set_map.c
set_exit -->					[5] ft_set_map.c
handle_input -->				[1] ft_hook.c
mousse_close_windows -->		[3] ft_hook.c
*/
