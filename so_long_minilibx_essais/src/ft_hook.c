/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:37 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/20 20:54:38 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
void	ft_r(void)
{
	int	write_error;

	write_error = write(1, "\r", 1);
	(void)write_error;
	return;
}
*/

int	handle_input(int keysym, t_vars *game)
{
	static int		count = 0;

	if (keysym == 65307)
	{
		ft_printf("\033[31m\n\n[ESC] Partie abandonnée !\n\n\033[0m");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	else if (keysym == 65361)
	{
		count++;
		ft_printf("\033[32mTouche gauche - mouvement [%d]\r\033[0m", count);
//		ft_r();
	}
	else if (keysym == 65362)
	{
		count++;
		ft_printf("\033[32mTouche haut   - mouvement [%d]\r\033[0m", count);
//		ft_r();
	}
	else if (keysym == 65363)
	{
		count++;
		ft_printf("\033[32mTouche droite - mouvement [%d]\r\033[0m", count);
//		ft_r();
	}
	else if (keysym == 65364)
	{
		count++;
		ft_printf("\033[32mTouche bas    - mouvement [%d]\r\033[0m", count);
//		ft_r();
	}
	return (0);
}
