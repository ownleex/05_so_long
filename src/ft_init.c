/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:35:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/24 04:28:02 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	calculate_win_x_y(t_vars *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
		y++;
	x = 0;
	while (game->map[0][x])
		x++;
	game->win_y = y * 100;
	game->win_x = x * 100;
}

int	ft_init(t_vars *game)
{
	//game->nbr_moov = 0;
	game->mlx_ptr = mlx_init();
	calculate_win_x_y(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_x, game->win_y, \
	"---> FireWater <---");
	game->green_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/green.xpm", &game->width, &game->height);
	game->tree_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/tree.xpm", &game->width, &game->height);
	game->fire_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire.xpm", &game->width, &game->height);
	game->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/exit.xpm", &game->width, &game->height);
	game->water_up = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_up.xpm", &game->width, &game->height);
	game->water_down = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_down.xpm", &game->width, &game->height);
	game->water_left = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_left.xpm", &game->width, &game->height);
	game->water_right = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_right.xpm", &game->width, &game->height);
	set_green(game);
	set_walls(game);
	set_fire(game);
	set_water_down(game);
	set_exit(game);
	game->str = "Ceci est test !";
	//mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 0xFFFFFF, game->str);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, handle_input, game);
	mlx_hook(game->win_ptr, 17, 0, mousse_close_window, game);
	mlx_loop(game->mlx_ptr);
	return (EXIT_SUCCESS);
}
