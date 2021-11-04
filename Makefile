# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <msousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/11/04 20:57:08 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -g -Wall -Wextra -Werror
LINKS		= -lmlx -lm -Llibft -lft
CC			= gcc
RM			= rm -f
INC			= -Iincludes -Ilibft
UNAME 	:= ${shell uname}
OBJ			= ${SRC:.c=.o}
SRC			= fractol.c srcs/my_mlx.c srcs/complex.c srcs/point.c srcs/range.c \
					srcs/utils.c srcs/formulas.c
					

NAME		= fractol

ifeq (${UNAME}, Linux)
LINKS += -lbsd -lXext -lX11
endif

ifeq (${UNAME}, Darwin)
LINKS += -framework OpenGL -framework AppKit
endif

${NAME}:	libft ${OBJ}
					${CC} ${CFLAGS} ${OBJ} ${LINKS} -o $@

libft:
					${MAKE} -C libft

%.o:%.c
					${CC} ${CFLAGS} ${INC} -c $< -o $@

all:			${NAME}

bonus:
					@echo "TBD"

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
