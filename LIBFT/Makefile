# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 12:54:31 by pcatapan          #+#    #+#              #
#    Updated: 2022/01/13 13:48:50 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= *.c

OBJS		= *.o

HEAD		= libft.h

NAME		= libft.a

RM			= rm -f

GCC			= GCC

CFLAGS		= -Werror -Wall -Wextra

all:		${NAME}

.c.o:
	${GCC} ${FLAGS} -c ${SRCS}
	
${NAME}:	${OBJS}
	${NAME}	${GCC} -I ${HEAD} -o ${OBJS} ${}