/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/17 19:07:31 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[j])
		return ((char *) haystack[i]);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j] && needle[j] && i < len)
		{
			while (haystack[i] == needle[j] && needle[j] && i < len)
			{
				i++;
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i - j]);
			}
		}
		i++;
	}
	return (NULL);
}
