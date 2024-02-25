/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:35:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/25 21:00:18 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <sys/time.h> 

int	ft_init(t_vars *game)
{
	//game->nbr_moov = 0;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_x * 100, game->win_y * 100, \
	"---> FireWater <---");
	game->green_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/green.xpm", &game->width, &game->height);
	game->tree_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/tree.xpm", &game->width, &game->height);
	game->fire_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire.xpm", &game->width, &game->height);
	game->water = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water.xpm", &game->width, &game->height);
	game->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/exit.xpm", &game->width, &game->height);
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
