/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:35:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 22:48:06 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	xpm_to_image(t_vars *game)
{
	game->green_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/green.xpm", &game->wi, &game->he);
	game->tree_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/tree.xpm", &game->wi, &game->he);
	game->fire_1_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire_1.xpm", &game->wi, &game->he);
	game->fire_2_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/fire_2.xpm", &game->wi, &game->he);
	game->water_up = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_up.xpm", &game->wi, &game->he);
	game->water_down = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_down.xpm", &game->wi, &game->he);
	game->water_left = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_left.xpm", &game->wi, &game->he);
	game->water_right = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/water_right.xpm", &game->wi, &game->he);
	game->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/exit.xpm", &game->wi, &game->he);
	game->egout = mlx_xpm_file_to_image(game->mlx_ptr, \
	"sprites/egout.xpm", &game->wi, &game->he);
}
/*
[4]
*/

void	string_screen(t_vars *game)
{
	char	*str;

	str = ft_itoa(game->cnt_moov);
	set_walls(game);
	set_green(game);
	mlx_string_put(game->mlx_ptr, game->win_ptr, \
	120, game->win_y * game->he - 100, 0xF33FFFF, "MOUVEMENT(S)");
	mlx_string_put(game->mlx_ptr, game->win_ptr, \
	100, game->win_y * game->he - 100, 0x33FFFF, str);
	mlx_string_put(game->mlx_ptr, game->win_ptr, \
	100, game->win_y * game->he - 90, 0xF33FFFF, "_______________");
	free(str);
}
/*
[3]
set_walls -->					[2] ft_set_map_bonus.c
set_green -->					[1] ft_set_map_bonus.c
*/

void	update_animation(t_vars *game, int *bool, struct timeval *last_change)
{
	struct timeval	current_time;
	long			time_difference;

	gettimeofday(&current_time, NULL);
	time_difference = (current_time.tv_sec - last_change->tv_sec) * \
	1000000L + (current_time.tv_usec - last_change->tv_usec);
	if (time_difference > 300000)
	{
		if (*bool)
			set_fire_2(game);
		else
			set_fire_1(game);
		*bool = !(*bool);
		*last_change = current_time;
	}
}

int	animation(t_vars *game)
{
	static int				bool = 1;
	static struct timeval	last_change = {0, 0};

	update_animation(game, &bool, &last_change);
	string_screen(game);
	return (1);
}
/*
[2]
string_screen -->				[3] -->here<--
*/

int	ft_init(t_vars *game)
{
	game->mlx_ptr = mlx_init();
	xpm_to_image(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->win_x * game->wi, game->win_y * game->he, "---> FireWater <---");
	set_green(game);
	set_walls(game);
	set_fire_1(game);
	set_water_down(game);
	set_exit(game);
	set_egout(game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_input, game);
	mlx_hook(game->win_ptr, 17, 0, &mousse_close_window, game);
	mlx_loop_hook(game->mlx_ptr, &animation, game);
	mlx_loop(game->mlx_ptr);
	return (EXIT_SUCCESS);
}
/*
[1]
set_green -->						[1] ft_set_map_bonus.c
set_walls -->						[2] ft_set_map_bonus.c
set_fire_1 -->						[2] ft_set_map_2_bonus.c
set_water_down -->					[3]	ft_set_water_bonus.c
set_exit -->						[3] ft_set_map_bonus.c
set_egout -->						[3] ft_set_map_2_bonus.c
handle_input -->					[1] ft_hook_bonus.c
mousse_close_windows -->			[3] ft_hook_bonus.c
animation -->						[2] -->here<--
*/
