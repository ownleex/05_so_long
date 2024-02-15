/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:37 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/15 00:39:19 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keysym, t_vars *game)
{
	static int		count = 0;

	if (keysym == 65307)
	{
		ft_printf("[ESC] Partie abandonnée !\n\n");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	else if (keysym == 65361)
	{
		count++;
		ft_printf("Touche gauche - mouvement [%d]\n\n", count);
	}
	else if (keysym == 65362)
	{
		count++;
		ft_printf("Touche haut - mouvement [%d]\n\n", count);	}
	else if (keysym == 65363)
	{
		count++;
		ft_printf("Touche droite - mouvement [%d]\n\n", count);	}
	else if (keysym == 65364)
	{
		count++;
		ft_printf("Touche bas - mouvement [%d]\n\n", count);	}
	return (0);
}
