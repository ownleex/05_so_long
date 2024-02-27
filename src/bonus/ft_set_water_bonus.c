/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_water_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:36:21 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 04:54:10 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	set_water_up(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->water_up != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->water_up, x * game->wi, y * game->he);
					game->player_x = x;
					game->player_y = y;
				}
			}
			x++;
		}
		y++;
	}
}

void	set_water_down(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->water_down != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->water_down, x * game->wi, y * game->he);
					game->player_x = x;
					game->player_y = y;
				}
			}
			x++;
		}
		y++;
	}
}

void	set_water_left(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->water_left != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->water_left, x * game->wi, y * game->he);
					game->player_x = x;
					game->player_y = y;
				}
			}
			x++;
		}
		y++;
	}
}

void	set_water_right(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->water_right != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->water_right, x * game->wi, y * game->he);
					game->player_x = x;
					game->player_y = y;
				}
			}
			x++;
		}
		y++;
	}
}
