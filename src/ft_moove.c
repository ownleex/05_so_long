/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:30:48 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/24 00:53:32 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	reset_map(t_vars *game, char str)
{
	set_green(game);
	if ( str == 'D')
		set_water_down(game);
	else if ( str == 'U')
		set_water_up(game);
	else if ( str == 'L')
		set_water_left(game);
	else if ( str == 'R')
		set_water_right(game);
}

void	move_down(t_vars *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			game->nbr_fire--;
		else if (game->map[y + 1][x] == 'E' && game->nbr_fire == 0)
		{
			you_win(game);
		}
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
		{
			game->map[y][x] = '0';
			game->player_y += 1;
			game->map[y + 1][x] = 'P';
			ft_printf("\033[34mMouvement  %d - Restant %d \r\033[0m", game->nbr_moov, game->nbr_fire);
		}
		reset_map(game, 'D');
	}
	else
	{
		game->nbr_moov--;
		ft_printf("\033[31mImpossible %d - Restant %d \033[0m\r", game->nbr_moov, game->nbr_fire);
	}
}

void	move_up(t_vars *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			game->nbr_fire--;
		else if (game->map[y - 1][x] == 'E' && game->nbr_fire == 0)
		{
			you_win(game);
		}
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
		{
			game->map[y][x] = '0';
			game->player_y -= 1;
			game->map[y - 1][x] = 'P';
			ft_printf("\033[34mMouvement  %d - Restant %d \r\033[0m", game->nbr_moov, game->nbr_fire);
		}
		reset_map(game, 'U');
	}
	else
	{
		game->nbr_moov--;
		ft_printf("\033[31mImpossible %d - Restant %d \033[0m\r", game->nbr_moov, game->nbr_fire);
	}
}

void	move_right(t_vars *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			game->nbr_fire--;
		else if (game->map[y][x + 1] == 'E' && game->nbr_fire == 0)
		{
			you_win(game);
		}
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
		{
			game->map[y][x] = '0';
			game->player_x += 1;
			game->map[y][x + 1] = 'P';
			ft_printf("\033[34mMouvement  %d - Restant %d \r\033[0m", game->nbr_moov, game->nbr_fire);
		}
		reset_map(game, 'R');
	}
	else
	{
		game->nbr_moov--;
		ft_printf("\033[31mImpossible %d - Restant %d \033[0m\r", game->nbr_moov, game->nbr_fire);
	}
}

void	move_left(t_vars *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			game->nbr_fire--;
		else if (game->map[y][x - 1] == 'E' && game->nbr_fire == 0)
		{
			you_win(game);
		}
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
		{
			game->map[y][x] = '0';
			game->player_x -= 1;
			game->map[y][x - 1] = 'P';
			ft_printf("\033[34mMouvement  %d - Restant %d \r\033[0m", game->nbr_moov, game->nbr_fire);
		}
		reset_map(game, 'L');
	}
	else
	{
		game->nbr_moov--;
		ft_printf("\033[31mImpossible %d - Restant %d \033[0m\r", game->nbr_moov, game->nbr_fire);
	}
}
