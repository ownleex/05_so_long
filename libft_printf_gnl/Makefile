# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:58:05 by ayarmaya          #+#    #+#              #
#    Updated: 2023/12/05 18:05:01 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFTNAME	=	libft.a

LIBFT_DIR	=	./libft

SRC		=	ft_printf \
			ft_printhex \
			ft_printint \
			ft_printptr \
			ft_printstr \
			ft_printuint \

SRCS		=	$(addsuffix .c, ${SRC})

OBJS		=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar crs

all:		${NAME}

make_libft:
			@make -C ${LIBFT_DIR}
			@cp ${LIBFT_DIR}/${LIBFTNAME} .
			@mv ${LIBFTNAME} ${NAME}

${NAME}: 	make_libft ${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			@cd ${LIBFT_DIR} && make clean

fclean:		clean
			${RM} ${NAME}
			@cd ${LIBFT_DIR} && make fclean

re:		fclean all

.PHONY:	all clean fclean re
