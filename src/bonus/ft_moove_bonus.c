/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:30:48 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 04:05:19 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
		set_green(game);
		set_water_down(game);
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
		set_green(game);
		set_water_up(game);
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
		set_green(game);
		set_water_right(game);
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
		set_green(game);
		set_water_left(game);
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
