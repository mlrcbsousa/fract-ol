# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/10/29 18:54:48 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror
CC			= gcc
RM			= rm -f
INC			= -I includes
OBJ			= ${SRC:.c=.o}
SRC			= main.c srcs/fractol.c

NAME		= fractol

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