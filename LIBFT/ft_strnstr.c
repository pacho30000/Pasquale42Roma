/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/13 17:17:40 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (((unsigned char *)haystack)[i] && ((unsigned char *)needle)[j]
		&& len > 0)
	{
		j = 0;
		if (((unsigned char *)needle)[j] != ((unsigned char *)haystack)[i])
		{
			i++;
			len--;
		}
		while (((unsigned char *)haystack)[i] == ((unsigned char *)needle)[j]
			&& len > 0 && ((unsigned char *)haystack)[i])
		{
			i++;
			j++;
			len--;
		}
	}
	return (0);
}
