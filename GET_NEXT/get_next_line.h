#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd)

#endif