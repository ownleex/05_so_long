/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:50:50 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 00:54:41 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <stdlib.h>
# include <X11/X.h>

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
	int		win_x;
	int		win_y;
	int		px;
	void	*green_ptr;
	void	*fire_ptr;
	void	*water_ptr;
	void	*tree_ptr;
	void	*exit_ptr;
	char	**map;
	int		green_x;
	int		green_y;
	int		fire_x;
	int		fire_y;
	int		water_x;
	int		water_y;
	int		tree_x;
	int		tree_y;
	int		exit_x;
	int		exit_y;
}				t_vars;

int		handle_input(int keysym, t_vars *game);
int		check_ber(char *map);
void	load_map(char *map_file, t_vars *game);
void	load_map_struct(t_list *temp_map, int line_count, t_vars *game);
void	remove_back_n(char *line);
void	exit_with_message(char *message);
void	exit_with_perror(char *message);
void	check_rectangular(char **map);
void	check_walls(char **map, size_t width, size_t height);
void	count_items_and_verify_chars(char **map, size_t width, size_t height);
void	increment_counters(char c, int *exit, int *items, int *start);
void	verify_char(char c);
int	    ft_init(t_vars *game);
void	calculate_win_x_y(t_vars *game);

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif