/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:56:41 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 20:36:51 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	verify_char(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		exit_with_message("\n\nError\nCaractère invalide dans la carte\n\n");
}

void	increment_counters(char c, int *exit, int *items, int *start)
{
	*exit += (c == 'E');
	*items += (c == 'C');
	*start += (c == 'P');
	verify_char(c);
}

void	count_items_and_verify_chars(char **map, size_t width, size_t height)
{
	size_t	x;
	size_t	y;
	int		exit;
	int		items;
	int		start;

	exit = 0;
	items = 0;
	start = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			increment_counters(map[y][x], &exit, &items, &start);
			x++;
		}
		y++;
	}
	if (exit != 1 || items < 1 || start != 1)
		exit_with_message("\n\nError\nNombre d'items incorrect\n\n");
}

void	check_walls(char **map, size_t width, size_t height)
{
	size_t	x;
	size_t	y;

	x = width;
	while (x--)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			exit_with_message("\n\nError\nMap pas entourée de murs\n\n");
	}
	y = height;
	while (y--)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			exit_with_message("\n\nError\nMap pas entourée de murs\n\n");
	}
	count_items_and_verify_chars(map, width, height);
}

void	check_rectangular(char **map)
{
	size_t	y;
	size_t	x;

	if (!map || !*map)
		exit_with_message("\n\nError\nLa carte est vide\n\n");
	y = 0;
	x = ft_strlen(map[y]);
	while (map[y])
	{
		if (ft_strlen(map[y]) != x)
			exit_with_message("\n\nError\nMap pas rectangulaire\n\n");
		y++;
	}
	check_walls(map, x, y);
}
