# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/10/29 19:52:41 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror 
CC			= gcc
RM			= rm -f
AR			= ar rcs
INC			= -I includes
UNAME 	:= ${shell uname}
OBJ			= ${SRC:.c=.o}
SRC			= main.c srcs/fractol.c

NAME		= fractol

ifeq (${UNAME}, Linux)
	CFLAGS += -lbsd -lmlx -lXext -lX11 -lm
endif

ifeq (${UNAME}, Darwin)
	CFLAGS += -lmlx -framework OpenGL -framework AppKit -lm
endif

${NAME}:	${OBJ}
					${CC} ${CFLAGS} -o $@ ${OBJ}

%.o:%.c
					${CC} ${CFLAGS} ${INC} -c $< -o $@
 
all:			${NAME}

bonus:		
					@echo "TBD"

test:			${NAME}
					-norminette $$( find . -type f \( -name "*.c" -or -name "*.h" \) | grep -v /mlx/ )
					@echo
					valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./${NAME}

clean:
					${RM} ${OBJ}

fclean:		clean
					${RM} ${NAME}

re: 			fclean all

.PHONY : 	all clean fclean re bonus