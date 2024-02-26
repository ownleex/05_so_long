# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 17:27:18 by ayarmaya          #+#    #+#              #
#    Updated: 2024/02/26 20:23:23 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
NAME_B	:= so_long_bonus

CFLAGS	:= -Wall -Wextra -Werror

HEADERS	:= -I/usr/include -Imlx_linux -I./include -Ilibft/include
LIBS	:= libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC	:= gcc
RM	:= rm -f

SRCS	:= $(shell find ./src -iname "*.c")
SRCS_B	:= $(shell find ./src -iname "*_bonus.c")

OBJS	:= ${SRCS:.c=.o}
OBJS_B	:= ${SRCS_B:.c=.o}

all: libftmlx $(NAME)

bonus: libftmlx $(NAME_B)

libftmlx:
	cd mlx_linux;./configure
	cd libft;make

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(NAME_B): $(OBJS_B)
	$(CC) $(OBJS_B) $(LIBS) -o $(NAME)

clean:
	${RM} $(OBJS)
	${RM} $(OBJS_B)
	cd libft;make clean
	cd mlx_linux;make clean

fclean: clean
	${RM} $(NAME)
	${RM} $(NAME_B)
	cd libft;make fclean
	cd mlx_linux;./configure clean
	cd mlx_linux;${RM} Makefile.gen

re: fclean all

.PHONY: all, bonus, clean, fclean, re, libftmlx