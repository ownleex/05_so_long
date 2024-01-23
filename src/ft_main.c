/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:56 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/01/23 18:56:59 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Please choose :\n===> 1 for Mandelbrot\n");
		ft_printf("===> 2 for Julia\n");
	}
	else
	{
		if (ft_strncmp(argv[1], "1", 1) == 0)
		{
			ft_printf("\n===> Mandelbroot fractal chosen.\n");
			ft_init("Mandelbrot fract-ol");
		}
		if (ft_strncmp(argv[1], "2", 1) == 0)
			
		{	ft_printf("\n===> Julia fractal chosen.\n");
			ft_init("Julia fract-ol");
		}
	}
	return (0);
}
