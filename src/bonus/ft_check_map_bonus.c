/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:56:41 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/28 01:38:30 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	verify_char(t_vars *game, char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != 'L')
		exit_with_message(game, \
		"\n\nError\nCaractère invalide dans la carte\n\n");
}
/*
[5]
exit_with_message -->			[3] ft_utils_bonus.c
*/

void	increment_counters(t_vars *game, char c)
{
	if (c == 'E')
		game->cnt_exit++;
	else if (c == 'C')
		game->cnt_items++;
	else if (c == 'P')
		game->cnt_start++;
	verify_char(game, c);
}
/*
[4]
verify_char -->					[5] -->here<--
*/

void	count_items_and_verify_chars(t_vars *game)
{
	int		x;
	int		y;

	game->cnt_exit = 0;
	game->cnt_items = 0;
	game->cnt_start = 0;
	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			increment_counters(game, game->map[y][x]);
			x++;
		}
		y++;
	}
	if (game->cnt_exit != 1 || game->cnt_items < 1 || game->cnt_start != 1)
		exit_with_message(game, "\n\nError\nNombre d'items incorrect\n\n");
	verify_path(game);
}
/*
[3]
increment_counters -->			[4] -->here<--
exit_with_message -->			[3] ft_utils_bonus.c
verify_path -->					[1] ft_check_road_bonus.c
*/

void	check_walls(t_vars *game)
{
	int		x;
	int		y;

	x = game->win_x;
	while (x--)
	{
		if (game->map[0][x] != '1' || game->map[game->win_y - 1][x] != '1')
			exit_with_message(game, "\n\nError\nMap pas entourée de murs\n\n");
	}
	y = game->win_y;
	while (y--)
	{
		if (game->map[y][0] != '1' || game->map[y][game->win_x - 1] != '1')
			exit_with_message(game, "\n\nError\nMap pas entourée de murs\n\n");
	}
	count_items_and_verify_chars(game);
}
/*
[2]
exit_with_message -->			[3] ft_utils_bonus.c
count_and_verify_chars -->		[3] -->here<--
*/

void	check_rectangular(t_vars *game)
{
	size_t	y;
	size_t	x;

	if (!game->map || !*game->map)
		exit_with_message(game, "\n\nError\nLa carte est vide\n\n");
	y = 0;
	x = ft_strlen(game->map[y]);
	while (game->map[y])
	{
		if (ft_strlen(game->map[y]) != x)
			exit_with_message(game, "\n\nError\nMap pas rectangulaire\n\n");
		y++;
	}
	check_walls(game);
}
/*
[1]
exit_with_message -->			[3] ft_utils_bonus.c
check_walls -->					[2] -->here<--
*/
