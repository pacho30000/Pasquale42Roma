# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:24:57 by pcatapan          #+#    #+#              #
#    Updated: 2022/01/24 17:32:20 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 

OBJS = ${SRCS:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror

INCS = .

LIBC = ar -rcs

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
	
$(NAME) : ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
all: $(NAME)

fclean:  clean
	$(RM) $(NAME)
	
clean:
	$(RM) -f $(OBJS)
	
re: fclean all