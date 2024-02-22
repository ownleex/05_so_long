# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 17:27:18 by ayarmaya          #+#    #+#              #
#    Updated: 2024/02/10 04:01:34 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= FireWater
CFLAGS	:= -Wall -Wextra -Werror

HEADERS	:= -I/usr/include -Imlx_linux -I./include -Ilibft/include
LIBS	:= libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC	:= gcc
RM	:= rm -f

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libftmlx $(NAME)

libftmlx:
	cd mlx_linux;./configure
	cd libft;make

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	${RM} $(OBJS)
	cd libft;make clean
	cd mlx_linux;make clean

fclean: clean
	${RM} $(NAME)
	cd libft;make fclean
	cd mlx_linux;./configure clean
	cd mlx_linux;${RM} Makefile.gen

re: fclean all

.PHONY: all, clean, fclean, re, libftmlx