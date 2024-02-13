/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:50:50 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/13 23:19:00 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <unistd.h>

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
	int		green_width, green_height;
	int		fire_width, fire_height;
	int		water_width, water_height;
	int		tree_width, tree_height;
	int		exit_width, exit_height;
}				t_vars;

int		handle_input(int keysym, t_vars *game);
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif