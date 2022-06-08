NAME		= philo

S = philo_M/

SRC = 	$Smain.c \
		$Sutils.c	\
		$Sdestroy.c \
		$Sstarter.c	\

PROJECT_H	= $Sphilosophers.h

OBJS = $(SRC:%.c=%.o)

RM = @rm -rf

PTHEAD_FLAG = -pthread
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra -fsanitize=thread


$(NAME): $(SRC)
	@$(CC) $(SRC) $(CC_FLAGS) $(PTHEAD_FLAG) -o $(NAME) 

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re