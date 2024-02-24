/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 02:23:20 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/24 04:29:16 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_exit(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y / 100)
	{
		x = 0;
		while (x < game->win_x / 100)
		{
			if (game->map[y][x] == 'E')
				if (game->exit_ptr != NULL)
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->exit_ptr, x * 100, y * 100);
			x++;
		}
		y++;
	}
}

void	set_fire(t_vars *game)
{
	int		x;
	int		y;

	game->nbr_fire = 0;
	y = 0;
	while (y < game->win_y / 100)
	{
		x = 0;
		while (x < game->win_x / 100)
		{
			if (game->map[y][x] == 'C')
			{
				if (game->fire_ptr != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->fire_ptr, x * 100, y * 100);
					game->nbr_fire++;
				}
			}
			x++;
		}
		y++;
	}
}

void	set_walls(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y / 100)
	{
		x = 0;
		while (x < game->win_x / 100)
		{
			if (game->map[y][x] == '1')
				if (game->tree_ptr != NULL)
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->tree_ptr, x * 100, y * 100);
			x++;
		}
		y++;
	}
}

void	set_green(t_vars *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->win_y / 100)
	{
		x = 0;
		while (x < game->win_x / 100)
		{
			if (game->map[y][x] == '0')
				if (game->green_ptr != NULL)
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->green_ptr, x * 100, y * 100);
			x++;
		}
		y++;
	}
}
