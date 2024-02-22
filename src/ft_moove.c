/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:30:48 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 17:48:14 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_down(t_vars *game, int count)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
		{
			game->nbr_fire--;
			ft_printf("\033[32mObjet collecté! Restants: %d %d\033[0m\r", game->nbr_fire, count);
		}
		else if (game->map[y + 1][x] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
		}
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
		{
			game->map[y][x] = '0';
			game->player_y += 1;
			game->map[y + 1][x] = 'P';
			ft_printf("\033[34mTouche bas - mouvement [%d]\r\033[0m", count);
		}
		set_green(game);
		set_water(game);
		set_exit(game);
	}
	else
		ft_printf("\033[31mMouvement impossible: il y a un mur! %d\033[0m\r", count);
}

void	move_up(t_vars *game, int count)
{
	int		x;
	int		y;
	
	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
		{
			game->nbr_fire--;
			ft_printf("\033[32mObjet collecté! Restants: %d %d\033[0m\r", game->nbr_fire, count);
		}
		else if (game->map[y - 1][x] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
		}
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
		{
			game->map[y][x] = '0';
			game->player_y -= 1;
			game->map[y - 1][x] = 'P';
			ft_printf("\033[34mTouche haut - mouvement [%d]\r\033[0m", count);
		}
		set_green(game);
		set_water(game);
		set_exit(game);
	}
	else
		ft_printf("\033[31mMouvement impossible: il y a un mur! %d\033[0m\r", count);
}

void	move_right(t_vars *game, int count)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
		{
			game->nbr_fire--;
			ft_printf("\033[32mObjet collecté! Restants: %d %d\033[0m\r", game->nbr_fire, count);
		}
		else if (game->map[y][x + 1] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
		}
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
		{
			game->map[y][x] = '0';
			game->player_x += 1;
			game->map[y][x + 1] = 'P';
			ft_printf("\033[34mTouche droite - mouvement [%d]\r\033[0m", count);
		}
		set_green(game);
		set_water(game);
		set_exit(game);
	}
	else
		ft_printf("\033[31mMouvement impossible: il y a un mur! %d\033[0m\r", count);
}

void	move_left(t_vars *game, int count)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
		{
			game->nbr_fire--;
			ft_printf("\033[32mObjet collecté! Restants: %d %d\033[0m\r", game->nbr_fire, count);
		}
		else if (game->map[y][x - 1] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
		}
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
		{
			game->map[y][x] = '0';
			game->player_x -= 1;
			game->map[y][x - 1] = 'P';
			ft_printf("\033[34mTouche gauche - mouvement [%d]\r\033[0m", count);
		}
		set_green(game);
		set_water(game);
		set_exit(game);
	}
	else
		ft_printf("\033[31mGauche Mouvement impossible: il y a un mur! %d\033[0m\r", count);
}
