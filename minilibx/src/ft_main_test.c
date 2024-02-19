/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:00:38 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/19 17:01:47 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	main2(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\n2 paramètres sont attendus");
		return (0);
	}
	else if (check_ber(argv[1]) == 0)
	{
		ft_printf("Error\nLa carte n'est pas un .ber");
		return (0);
	}
	else
	{
		load_map(argv[1])
	}
	return (1);
}


void	ft_r(void)
{
	int	write_error;

	write_error = write(1, "\r", 1);
	(void)write_error;
}