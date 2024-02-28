/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_road_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 02:40:31 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/28 01:17:12 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_game_visited(t_vars *game)
{
	int		y;

	y = 0;
	while (y < game->win_y)
	{
		free(game->visited[y]);
		y++;
	}
	free(game->visited);
}
/*
[5]
*/

void	compare_count_items(t_vars *game)
{
	if (game->cnt_items != game->visited_items)
		exit_with_message(game, "\n\nError\nItems non récupréables\n\n");
}
/*
[4]
exit_with_message -->			[3] ft_utils_bonus.c
*/

void	dfs(t_vars *game, int y, int x, int **visited)
{
	if (y < 0 || x < 0 || y >= game->win_y || x >= game->win_x \
	||game->map[y][x] == '1' || visited[y][x] || game->map[y][x] == 'L')
		return ;
	visited[y][x] = 1;
	if (game->map[y][x] == 'E')
	{
		game->path_found = 1;
		return ;
	}
	else if (game->map[y][x] == 'C')
		game->visited_items = game->visited_items + 1;
	dfs(game, y + 1, x, visited);
	dfs(game, y - 1, x, visited);
	dfs(game, y, x + 1, visited);
	dfs(game, y, x - 1, visited);
}
/*
[3]
*/

void	find_start_position(t_vars *game, int *start_y, int *start_x)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (game->map[y][x] == 'P')
			{
				*start_y = y;
				*start_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
/*
[2]
*/

void	verify_path(t_vars *game)
{
	int	y;
	int	start_x;
	int	start_y;

	start_x = 0;
	start_y = 0;
	y = 0;
	game->visited = malloc(sizeof(int *) * game->win_y);
	while (y < game->win_y)
	{
		game->visited[y] = ft_calloc(game->win_x, sizeof(int));
		y++;
	}
	game->path_found = 0;
	find_start_position(game, &start_y, &start_x);
	dfs(game, start_y, start_x, game->visited);
	if (!game->path_found)
	{
		free_game_visited(game);
		exit_with_message(game, "\n\nError\nAucun chemin valide trouvé\n\n");
	}
	free_game_visited(game);
	compare_count_items(game);
}
/*
[1]
find_start_position -->			[2] -->here<--
dfs -->							[3] -->here<--
free_game_visited -->			[5] -->here<--
compare_count_items -->			[4] -->here<--
-----
[3] count_item_and_ver...		ft_check_map_bonus.c
*/
