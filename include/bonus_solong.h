/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_solong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:03:40 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/25 17:04:40 by ayarmaya         ###   ########.fr       */
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
# include <sys/time.h> 

typedef struct	s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_x;
	int		win_y;
	void	*green_ptr;
	void	*fire_ptr;
	void	*water_ptr;
	void	*water;
	void	*tree_ptr;
	void	*fire_right;
	void	*fire_up;
	void	*fire_left;
	void	*exit_ptr;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		nbr_fire;
	int		nbr_moov;
	char	*str;
}				t_vars;

void	exit_with_message(char *message);
void	exit_with_perror(char *message);

int		check_ber(char *map);

void	load_map(char *map_file, t_vars *game);
void	load_map_struct(t_list *temp_map, int line_count, t_vars *game);
void	remove_back_n(char *line);
void	free_temp_map(t_list *temp_map);

void	check_rectangular(char **map);
void	check_walls(char **map, size_t width, size_t height);
void	count_items_and_verify_chars(char **map, size_t width, size_t height);
void	increment_counters(char c, int *exit, int *items, int *start);
void	verify_char(char c);

int	    ft_init(t_vars *game);
void	calculate_win_x_y(t_vars *game);

int		animation(t_vars *game);
int		handle_input(int keysym, t_vars *game);
int		mousse_close_window(t_vars *vars);
int		you_win(t_vars *game);

void	set_green(t_vars *game);
void	set_walls(t_vars *game);
void	set_water(t_vars *game);
void	set_fire(t_vars *game);
void	set_exit(t_vars *game);

void	move_left(t_vars *game);
void	move_right(t_vars *game);
void	move_up(t_vars *game);
void	move_down(t_vars *game);
void	reset_map(t_vars *game);

void	set_fire_right(t_vars *game);
void	set_fire_left(t_vars *game);
void	set_fire_up(t_vars *game);

#endif