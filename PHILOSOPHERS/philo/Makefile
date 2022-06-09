NAME		= philo


SRC = 	main.c \
		utils.c	\
		destroy.c \
		print.c \
		data_rice.c \
		starter.c	\

PROJECT_H	= philosophers.h

OBJS = $(SRC:%.c=%.o)

RM = @rm -rf

PTHEAD_FLAG = -pthread
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra #-fsanitize=thread


$(NAME): $(SRC)
	@$(CC) $(SRC) $(CC_FLAGS) $(PTHEAD_FLAG) -o $(NAME) 

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re