/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:50:50 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/27 04:01:26 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*fire_1_ptr;
	void	*fire_2_ptr;
	void	*water_up;
	void	*water_down;
	void	*water_left;
	void	*water_right;
	void	*tree_ptr;
	void	*exit_ptr;
	void	*egout;
	char	**map;
	int		cnt_exit;
	int		cnt_items;
	int		cnt_start;
	int		cnt_moov;
	int		wi;
	int		he;
	int		player_x;
	int		player_y;
	int		path_found;
	int		visited_items;
	int		**visited;
}				t_vars;

void	exit_with_message(t_vars *game, char *message);
void	exit_with_perror(t_vars *game, char *message);
void	free_all_exit(t_vars *game);
void	you_loose(char item, t_vars *game);

int		check_ber(char *map);
void	calculate_win_x_y(t_vars *game);
void	load_check_init(t_vars *game, char *argv);

void	init_vars(t_vars *game);
void	load_map(char *map_file, t_vars *game);
void	load_map_struct(t_list *temp_map, int line_count, t_vars *game);
void	remove_back_n(char *line);
void	free_temp_map(t_list *temp_map);
int		main(int argc, char **argv);

void	check_rectangular(t_vars *game);
void	check_walls(t_vars *game);
void	count_items_and_verify_chars(t_vars *game);
void	increment_counters(t_vars *game, char c);
void	verify_char(t_vars *game, char c);

void	free_game_visited(t_vars *game);
void	compare_count_items(t_vars *game);
void	dfs(t_vars *game, int y, int x, int **visited);
void	verify_path(t_vars *game);
void	find_start_position(t_vars *game, int *start_y, int *start_x);

int		ft_init(t_vars *game);
int		animation(t_vars *game);
void	string_screen(t_vars *game);

int		handle_input(int keysym, t_vars *game);
int		mousse_close_window(t_vars *game);
void	you_win(t_vars *game);
void	exit_destroy_game(t_vars *game);
void	impossible_move(t_vars *game);

void	set_green(t_vars *game);
void	set_walls(t_vars *game);
void	set_fire(t_vars *game);
void	set_exit(t_vars *game);

void	set_fire_1(t_vars *game);
void	set_fire_2(t_vars *game);
void	set_egout(t_vars *game);

void	set_water_up(t_vars *game);
void	set_water_down(t_vars *game);
void	set_water_left(t_vars *game);
void	set_water_right(t_vars *game);

void	move_left(t_vars *game);
void	move_right(t_vars *game);
void	move_up(t_vars *game);
void	move_down(t_vars *game);
void	reset_map(t_vars *game);

#endif