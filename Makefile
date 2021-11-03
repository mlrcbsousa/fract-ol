# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/11/03 15:17:54 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror
LINKS		= -lmlx -lm -Llibft -lft
CC			= gcc
RM			= rm -f
INC			= -Iincludes -Ilibft
UNAME 	:= ${shell uname}
OBJ			= ${SRC:.c=.o}
SRC			= main.c srcs/my_mlx.c srcs/color.c srcs/color_shade.c \
					srcs/complex.c srcs/point.c srcs/range.c

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
ifeq (${UNAME}, Linux)
					valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
					--num-callers=20 --track-fds=yes ./${NAME}
endif
ifeq (${UNAME}, Darwin)
					leaks -atExit -- ./${NAME}
endif

clean:
					${MAKE} clean -C libft
					${RM} ${OBJ}

fclean:		clean
					${RM} ${NAME}

re: 			fclean all

.PHONY : 	all clean fclean re bonus libft
