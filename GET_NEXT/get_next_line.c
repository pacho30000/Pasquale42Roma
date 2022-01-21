#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char	*freemalloc(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

static char	*printline(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		line = ft_substr(str, 0, i);
		i++;
	}
	else
	{
		line = ft_strdup(str);
 		/* ft_substr(str, 0, i);
		line[i] = '\0'; */
	}
	return (line);
}

static char	*readresult(int fd, char *buffer)
{
	int			res;
	int			i;
	char		*temp;
	static char	*str;
	char		*line;

	res = 1;
	i = 0;
	if (str == NULL)
		str = ft_strdup("");
	while (!ft_strchr(buffer, '\n') && res)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		buffer[res] = '\0';
		if (res == -1)
			freemalloc(buffer);
		temp = str;
		str = ft_strjoin(temp, buffer);
		if (!str)
			freemalloc(str);
		freemalloc(temp);
	}
	freemalloc(buffer);
	res = ft_strlen(str);
	while (str[i] != '\n')
		i++;
	line = ft_substr(str, 0, i);
	line = printline(line);
	str = ft_substr(str, i + 1, res);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		freemalloc(buffer);
	str = readresult(fd, buffer);
	return (str);
}

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	int	i = 3;
	int	fd = open("test", O_RDONLY);
	char	*test;

	if (fd < 0)
		return (0);
	while (i != 0)
	{
		test = get_next_line(fd);
		if (test)
			printf("%s\n", test);
		else
			printf("test doesnt exist\n");
		i--;
	}
	close(fd);
}