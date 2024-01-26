/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:35 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/01/23 18:56:37 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_init(char *fract)
{
	/*t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		ft_printf("Error : mlx_ptr/n");
		return (MLX_ERROR);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, fract);*/
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_printf("Error : mlx_ptr\n");
		return (MLX_ERROR);
	}
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, fract);
	if (win_ptr == NULL)
	{
		ft_mlx_error(mlx_ptr, win_ptr);
	}
	ft_printf("Window created.\n");
	ft_printf("\nPress ESC to quit window.\n");
	mlx_loop(mlx_ptr);
	ft_mlx_free(mlx_ptr, win_ptr);
	return (0);
}
