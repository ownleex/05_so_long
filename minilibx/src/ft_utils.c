/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:57:11 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/01/23 18:57:25 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_error(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_display(mlx_ptr);
	free(win_ptr);
	free(mlx_ptr);
	ft_printf("Error : no window created\n");
	return (MLX_ERROR);
}

void	ft_mlx_free(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
