/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:06:49 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 14:32:22 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_with_message(t_vars *game, char *message)
{
	int		y;

	ft_printf("%s", message);
	if (game->map)
	{
		y = 0;
		while (game->map[y])
		{
			free(game->map[y]);
			y++;
		}
		free(game->map);
	}
	free(game);
	exit(EXIT_FAILURE);
}
/*
[3]
*/

void	exit_with_perror(t_vars *game, char *message)
{
	perror(message);
	free(game);
	exit(EXIT_FAILURE);
}
/*
[2]
*/

void	free_all_exit(t_vars *game)
{
	int		y;

	if (game->map)
	{
		y = 0;
		while (game->map[y])
		{
			free(game->map[y]);
			y++;
		}
		free(game->map);
	}
	mlx_destroy_image(game->mlx_ptr, game->green_ptr);
	mlx_destroy_image(game->mlx_ptr, game->fire_ptr);
	mlx_destroy_image(game->mlx_ptr, game->water_ptr);
	mlx_destroy_image(game->mlx_ptr, game->tree_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(EXIT_SUCCESS);
}
/*
[1]
*/
