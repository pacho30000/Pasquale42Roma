# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 07:28:35 by pcatapan          #+#    #+#              #
#    Updated: 2022/05/05 18:14:36 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./src/*.c ./PRINTF/*.c ./src/element/*.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

KIT = -l mlx -framework openGL -framework AppKit

$(NAME) :
	@$(CC) $(SRCS) $(FLAGS) $(KIT) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -rf $(NAME) 
	
re: $(NAME)

norm:
	@norminette -R ./src/*.c ./PRINTF

.PHONY : all clean fclean re
