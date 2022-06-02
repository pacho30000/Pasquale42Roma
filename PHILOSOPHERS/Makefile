NAME		= philo

S = philo_M/

SRC = 	$Smain \
		$Sutils	\
		$Sstarter	\

PROJECT_H	= $Sphilosophers.h

OBJS = $(addsuffix .o, $(SRC))

RM = @rm -rf

PTHEAD_FLAG = -pthread
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra


$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CC_FLAGS) $(PTHEAD_FLAG)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re