/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:56:41 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/19 14:38:49 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_road()
{

}

void	check_items()
{

}

int	check_rectangular(char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
		x++;
	while (map[y][x])
		y++;
	if (x == y)
	{
		ft_printf("Error\nLa carte n'est pas rectangulaire");
		return (0);
	}
	return (1);
}
