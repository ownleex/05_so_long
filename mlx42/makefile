# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 17:27:18 by ayarmaya          #+#    #+#              #
#    Updated: 2024/01/29 17:59:17 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= libft/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

CC	:= gcc
RM	:= rm -rf

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	cd libft;make

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBMLX)/build
	cd libft;make clean

fclean: clean
	$(RM) $(NAME)
	cd libft;make fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx