/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_road.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 02:40:31 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/26 03:19:04 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dfs(t_vars *game, int y, int x, int **visited)
{
	if (y < 0 || x < 0 || y >= game->win_y || x >= game->win_x \
	||game->map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	if (game->map[y][x] == 'E')
	{
		game->path_found = 1;
		return ;
	}
	dfs(game, y + 1, x, visited);
	dfs(game, y - 1, x, visited);
	dfs(game, y, x + 1, visited);
	dfs(game, y, x - 1, visited);
}

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
		exit_with_message(game, "\n\nError\nAucun chemin valide trouvé\n\n");
	y = 0;
	while (y < game->win_y)
	{
		free(game->visited[y]);
		y++;
	}
	free(game->visited);
}