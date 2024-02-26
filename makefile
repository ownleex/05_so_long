# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 17:27:18 by ayarmaya          #+#    #+#              #
#    Updated: 2024/02/26 22:08:49 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
NAME_B := so_long_bonus

CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

LIBFT := libft/libft.a
MLX := mlx_linux/libmlx_Linux.a
MLX_FLAGS := -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

HEADERS := -I./include -Ilibft/include -Imlx_linux
LIBS := $(LIBFT) $(MLX) $(MLX_FLAGS)

SRCS := 	src/ft_check_map.c \
			src/ft_check_road.c \
			src/ft_hook.c \
			src/ft_init.c \
			src/ft_load_map.c \
			src/ft_main.c \
			src/ft_moove.c \
			src/ft_set_map.c \
			src/ft_utils.c

SRCS_B := 	src/bonus/ft_check_map_bonus.c \
			src/bonus/ft_check_road_bonus.c \
			src/bonus/ft_hook_bonus.c \
			src/bonus/ft_init_bonus.c \
			src/bonus/ft_load_map_bonus.c \
			src/bonus/ft_main_bonus.c \
			src/bonus/ft_moove_bonus.c \
			src/bonus/ft_set_map_bonus.c \
			src/bonus/ft_set_map_2_bonus.c \
			src/bonus/ft_utils_bonus.c

OBJS := $(SRCS:.c=.o)
OBJS_B := $(SRCS_B:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS)
	make -C libft
	make -C mlx_linux
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(NAME_B): $(OBJS_B)
	make -C libft
	make -C mlx_linux
	$(CC) $(OBJS_B) $(LIBS) -o $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make -C libft clean
	make -C mlx_linux clean

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
