/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:37 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/13 23:52:59 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keysym, t_vars *game)
{
	if(keysym)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	return(0);
}