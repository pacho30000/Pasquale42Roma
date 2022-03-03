/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 02:04:56 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/23 13:55:26 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		rd;
	int		i;
	char	c;
	char	*buffer;

	i = 0;
	buffer =(char *)malloc(sizeof(char) * 9999);
	while ((rd = read (fd, &c, (BUFFER_SIZE * 0 + 1)) > 0))
	{
		buffer[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (!buffer[i - 1] || !rd ) || (read < 0 || !rd))
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

#include <fcntl.h>

int		main(void)
{
	int i;
	int	fd;

	fd = open("txt.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}
