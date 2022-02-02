# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 12:48:00 by pcatapan          #+#    #+#              #
#    Updated: 2022/02/01 16:54:36 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_char.c		 \
		ft_esadecimal.c  \
		ft_putnumber.c 	 \
		ft_unsigned.c	 \
		ft_printf.c		 \
		ft_printf_utils.c \

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

.PHONY: all clean fclean re .c.o