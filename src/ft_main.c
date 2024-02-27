/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:00:38 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 16:43:59 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	calculate_win_x_y(t_vars *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
		y++;
	x = 0;
	while (game->map[0][x])
		x++;
	game->win_y = y;
	game->win_x = x;
}
/*
[5]
*/

void	load_check_init(t_vars *game, char *argv)
{
	load_map(argv, game);
	calculate_win_x_y(game);
	check_rectangular(game);
	ft_init(game);
}
/*
[4]
load_map -->					[1] ft_load_map.c
calculate_win_x_y -->			[5] --here--
check_rectangular -->			[1] ft_check_map.c
ft_init -->						[1] ft_init.c
*/

void	init_vars(t_vars *game)
{
	game->map = NULL;
	game->cnt_items = 0;
	game->visited_items = 0;
	game->path_found = 0;
	game->visited = NULL;
	game->cnt_moov = 0;
	game->win_ptr = NULL;
}
/*
[3]
*/

int	check_ber(char *map)
{
	int	i;

	i = ft_strlen(map);
	ft_printf("\n");
	if (map[i - 4] != '.' || map[i - 3] != 'b'
		|| map[i - 2] != 'e' || map[i - 1] != 'r')
		return (0);
	return (1);
}
/*
[2]
*/

int	main(int argc, char **argv)
{
	t_vars	*game;

	if (argc != 2)
	{
		ft_printf("\nError\n2 paramètres sont attendus\n\n");
		return (0);
	}
	else if (check_ber(argv[1]) == 0)
	{
		ft_printf("\nError\nLa carte n'est pas un .ber\n\n");
		return (0);
	}
	else
	{
		game = malloc(sizeof(t_vars));
		if (!game)
		{
			ft_printf("\nError\nProblème d'allocation mémoire pour game.\n");
			return (1);
		}
		init_vars(game);
		load_check_init(game, argv[1]);
	}
	return (1);
}
/*
[1]
check_ber -->					[2] --here--
init_vars -->					[3] --here--
load_check_init -->				[4] --here--
*/