# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/10/30 16:06:15 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror
LINKS		= -lmlx -lm
CC			= gcc
RM			= rm -f
INC			= -I includes
UNAME 	:= ${shell uname}
OBJ			= ${SRC:.c=.o}
SRC			= main.c srcs/fractol.c

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
					${CC} ${CFLAGS} ${INC} -c $< -o $@

all:			${NAME}

bonus:
					@echo "TBD"

test:			${NAME}
					-norminette $$( find . -type f \( -name "*.c" -or -name "*.h" \) )
					@echo
ifeq (${UNAME}, Linux)
					valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./${NAME}
endif
ifeq (${UNAME}, Darwin)
					leaks -atExit -- ./${NAME}
endif

clean:
					${RM} ${OBJ}

fclean:		clean
					${RM} ${NAME}

re: 			fclean all

.PHONY : 	all clean fclean re bonus
