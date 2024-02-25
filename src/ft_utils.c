/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:06:49 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/25 21:27:19 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_with_message(t_vars *game, char *message)
{
	int		y;

	ft_printf("%s", message);
	if (game->map)
	{
		y = 0;
		while (game->map[y])
		{
			free(game->map[y]);
			y++;
		}
		free(game->map);
	}
	free(game);
	exit(EXIT_FAILURE);
}


void	exit_with_perror(t_vars *game, char *message)
{
	perror(message);
	free(game);
	exit(EXIT_FAILURE);
}
