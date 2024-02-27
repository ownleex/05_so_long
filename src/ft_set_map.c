/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 02:23:20 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 16:36:14 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_exit(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == 'E')
				if (game->exit_ptr != NULL)
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->exit_ptr, x * game->wi, y * game->he);
			x++;
		}
		y++;
	}
}
/*
[5]
*/

void	set_fire(t_vars *game)
{
	int		x;
	int		y;

	game->cnt_items = 0;
	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == 'C')
			{
				if (game->fire_ptr != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->fire_ptr, x * game->wi, y * game->he);
					game->cnt_items++;
				}
			}
			x++;
		}
		y++;
	}
}
/*
[4]
*/

void	set_water(t_vars *game)
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
				if (game->water_ptr != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->water_ptr, x * game->wi, y * game->he);
					game->player_x = x;
					game->player_y = y;
				}
			}
			x++;
		}
		y++;
	}
}
/*
[3]
*/

void	set_walls(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == '1')
				if (game->tree_ptr != NULL)
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->tree_ptr, x * game->wi, y * game->he);
			x++;
		}
		y++;
	}
}
/*
[2]
*/

void	set_green(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == '0')
				if (game->green_ptr != NULL)
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->green_ptr, x * game->wi, y * game->he);
			x++;
		}
		y++;
	}
}
/*
[1]
*/
