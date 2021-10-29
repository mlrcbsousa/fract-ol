# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/10/29 16:05:35 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror
CC			= gcc
RM			= rm -f
INC			= -I includes
OBJS		= ${SRCS:.c=.o}
SRCS		= main.c srcs/fractol.c

NAME		= fractol

${NAME}:	${OBJS}
					${CC} ${CFLAGS} -o $@ ${OBJS}

%.o:%.c
					${CC} ${CFLAGS} ${INC} -c $< -o $@

all:			${NAME}

bonus:		
					@echo "TBD"

test:			${NAME}
					@norminette

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re: 			fclean all

.PHONY : 	all clean fclean re bonus