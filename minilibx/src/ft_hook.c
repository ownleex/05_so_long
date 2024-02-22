/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:37 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 03:35:32 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	mousse_close_window(t_vars *game)
{
	ft_printf("\033[5m\033[31m\n\nPartie abandonnée !\n\n\033[0m");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_input(int keysym, t_vars *game)
{
	static int		count = 0;

	if (keysym == 65307)
	{
		ft_printf("\033[5m\033[31m\n\n[ESC] Partie abandonnée !\n\n\033[0m");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	else if (keysym == 65361 || keysym == 97)
	{
		count++;
		ft_printf("\033[34mTouche gauche - mouvement [%d]\r\033[0m", count);
	}
	else if (keysym == 65362 || keysym == 119)
	{
		count++;
		ft_printf("\033[34mTouche haut   - mouvement [%d]\r\033[0m", count);
	}
	else if (keysym == 65363 || keysym == 100)
	{
		count++;
		ft_printf("\033[34mTouche droite - mouvement [%d]\r\033[0m", count);
	}
	else if (keysym == 65364 || keysym == 115)
	{
		count++;
		ft_printf("\033[34mTouche bas    - mouvement [%d]\r\033[0m", count);
	}
	else
	{
		ft_printf("\033[31mTouche invalide !              \r\033[0m");
	}
	return (0);
}
