/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:43:47 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/15 13:09:18 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		l;
	char				*str;
	unsigned int		i;

	l = ft_strlen((char *)s);
	str = (char *)malloc(len * sizeof(char));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i <= l && len > 0)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	i++;
	str[i] = '\0';
	return (str);
}
