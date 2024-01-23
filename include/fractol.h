/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:24:33 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/23 18:34:39 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include "../libft/include/libft.h"
# include "keys.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1200
# define HEIGHT 800

# define MLX_ERROR -1

# define MANDERBROT 1
# define JULIA 2

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;

}		t_mlx_data;

int		ft_hook(int e);
int		ft_init(char *fract);
int		ft_mlx_error(void *mlx_ptr, void *wim_ptr);
void	ft_mlx_free(void *mlx_ptr, void *win_ptr);

#endif
