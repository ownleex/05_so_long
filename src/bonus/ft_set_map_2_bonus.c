/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:34:40 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/26 22:28:34 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	set_fire_1(t_vars *game)
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
				if (game->fire_1_ptr != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->fire_1_ptr, x * game->wi, y * game->he);
					game->cnt_items++;
				}
			}
			x++;
		}
		y++;
	}
}

void	set_fire_2(t_vars *game)
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
				if (game->fire_2_ptr != NULL)
				{
					mlx_put_image_to_window(game->mlx_ptr, \
					game->win_ptr, game->fire_2_ptr, x * game->wi, y * game->he);
					game->cnt_items++;
				}
			}
			x++;
		}
		y++;
	}
}