/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:36:51 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/21 22:50:57 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char ft_readfile (int fd, char *buffer)
{
	int	n;
	char *str;

	if (str == NULL)
		str = ft_strdup("");
	while (!ft_strchr(buffer, '\n' && n))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			buffer = NULL;
		}
		buffer[n] = '\0';
		str = ft_strjoin(str, buffer);
		if(!str)
			return(NULL);
		free(buffer);
		buffer = NULL;		
	}
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	str = ft_readfile(fd, buffer);
	
}
