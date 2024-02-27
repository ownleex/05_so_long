/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:49:37 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 16:34:23 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	impossible_move(t_vars *game)
{
	game->cnt_moov--;
	ft_printf("\033[31mImpossible %d - Restant %d \033[0m\r", \
	game->cnt_moov, game->cnt_items);
}
/*
[5]
*/

void	exit_destroy_game(t_vars *game)
{
	ft_printf("\033[5m\033[31m\n\n[ESC] : Partie quittée !\n\n\033[0m");
	free_all_exit(game);
}
/*
[4]
free_all_exit -->				[1] ft_utils.c
*/

int	mousse_close_window(t_vars *game)
{
	ft_printf("\033[5m\033[31m\n\n[X Close] : Partie quittée !\n\n\033[0m");
	free_all_exit(game);
	exit(EXIT_SUCCESS);
}
/*
[3]
free_all_exit -->				[1] ft_utils.c
*/

void	you_win(t_vars *game)
{
	ft_printf("\033[5m\033[31m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
	free_all_exit(game);
}
/*
[2]
free_all_exit -->				[1] ft_utils.c
*/

int	handle_input(int keysym, t_vars *game)
{
	game->cnt_moov++;
	if (keysym == 65307)
		exit_destroy_game(game);
	else if (keysym == 65361 || keysym == 97)
		move_left(game);
	else if (keysym == 65362 || keysym == 119)
		move_up(game);
	else if (keysym == 65363 || keysym == 100)
		move_right(game);
	else if (keysym == 65364 || keysym == 115)
		move_down(game);
	else
	{
		ft_printf("\033[31mTouche invalide !              \r\033[0m");
		game->cnt_moov--;
	}
	return (0);
}
/*
[1]
exit_destroy_game -->			[4] -->here<--
move_left -->					[1] ft_move.c
move_up -->						[3] ft_move.c
move_right -->					[2] ft_move.c
move_down -->					[4] ft_move.c
*/
