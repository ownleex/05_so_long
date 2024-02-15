/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:50:50 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/14 21:53:22 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
//# include <unistd.h>

//typedef struct	s_data {
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}				t_data;

typedef struct	s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_green_ptr;
	void	*img_fire_ptr;
	void	*img_water_ptr;
	void	*img_tree_ptr;
	void	*img_exit_ptr;
	int		green_width;
	int		green_height;
	int		fire_width;
	int		fire_height;
	int		water_width;
	int		water_height;
	int		tree_width;
	int		tree_height;
	int		exit_width;
	int		exit_height;
}				t_vars;

int		handle_input(int keysym, t_vars *game);
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif