# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/11/08 21:06:56 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -g -Wall -Wextra -Werror
LINKS		= -lmlx -lm -Llibft -lft
CC			= gcc
RM			= rm -f
INC			= -Iincludes -Ilibft
UNAME 	:= ${shell uname}
OBJ			= ${SRC:.c=.o}
SRC			= fractol.c srcs/point.c srcs/range.c srcs/draw.c srcs/hooks.c\
					srcs/formulas.c

NAME		= fractol

ifeq (${UNAME}, Linux)
LINKS += -lbsd -lXext -lX11
endif

ifeq (${UNAME}, Darwin)
LINKS += -framework OpenGL -framework AppKit
endif

${NAME}:	${OBJ}
					${CC} ${CFLAGS} ${OBJ} ${LINKS} -o $@

%.o:%.c
					${MAKE} -C libft
					${CC} ${CFLAGS} ${INC} -c $< -o $@

all:			${NAME}

test:			${NAME}
					-norminette $$( find . -type f \( -name "*.c" -or -name "*.h" \) )
					@echo
					valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
					--num-callers=20 --track-fds=yes ./${NAME}

clean:
					${MAKE} clean -C libft
					${RM} ${OBJ}

fclean:		clean
					${RM} ${NAME}

re: 			fclean all

.PHONY : 	all clean fclean re bonus libft
