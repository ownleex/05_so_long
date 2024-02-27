/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:30:48 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 02:43:05 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	reset_map(t_vars *game)
{
	set_water(game);
	set_green(game);
}
/*
set_water -->				ft_set_map.c
set_green -->				ft_set_map.c
*/

void	move_down(t_vars *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			game->cnt_items--;
		else if (game->map[y + 1][x] == 'E' && game->cnt_items == 0)
			you_win(game);
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
		{
			game->map[y][x] = '0';
			game->player_y += 1;
			game->map[y + 1][x] = 'P';
			ft_printf("\033[5m\033[34mMouvement  %d - Restant %d \r\033[0m", \
			game->cnt_moov, game->cnt_items);
		}
		reset_map(game);
		you_loose(game->map[y + 1][x], game);
	}
	else
		impossible_move(game);
}
/*
you_win -->					ft_hook.c
reset_map -->				-->here<--
impossible_move -->			ft_hook.c
you_loose -->				ft_utils.c
*/

void	move_up(t_vars *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			game->cnt_items--;
		else if (game->map[y - 1][x] == 'E' && game->cnt_items == 0)
			you_win(game);
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
		{
			game->map[y][x] = '0';
			game->player_y -= 1;
			game->map[y - 1][x] = 'P';
			ft_printf("\033[5m\033[34mMouvement  %d - Restant %d \r\033[0m", \
			game->cnt_moov, game->cnt_items);
		}
		reset_map(game);
		you_loose(game->map[y - 1][x], game);
	}
	else
		impossible_move(game);
}
/*
you_win -->					ft_hook.c
reset_map -->				-->here<--
impossible_move -->			ft_hook.c
*/

void	move_right(t_vars *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			game->cnt_items--;
		else if (game->map[y][x + 1] == 'E' && game->cnt_items == 0)
			you_win(game);
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
		{
			game->map[y][x] = '0';
			game->player_x += 1;
			game->map[y][x + 1] = 'P';
			ft_printf("\033[5m\033[34mMouvement  %d - Restant %d \r\033[0m", \
			game->cnt_moov, game->cnt_items);
		}
		reset_map(game);
		you_loose(game->map[y][x + 1], game);
	}
	else
		impossible_move(game);
}
/*
you_win -->					ft_hook.c
reset_map -->				-->here<--
impossible_move -->			ft_hook.c
*/

void	move_left(t_vars *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			game->cnt_items--;
		else if (game->map[y][x - 1] == 'E' && game->cnt_items == 0)
			you_win(game);
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
		{
			game->map[y][x] = '0';
			game->player_x -= 1;
			game->map[y][x - 1] = 'P';
			ft_printf("\033[5m\033[34mMouvement  %d - Restant %d \r\033[0m", \
			game->cnt_moov, game->cnt_items);
		}
		reset_map(game);
		you_loose(game->map[y][x - 1], game);
	}
	else
		impossible_move(game);
}
/*
you_win -->					ft_hook.c
reset_map -->				-->here<--
impossible_move -->			ft_hook.c
*/
