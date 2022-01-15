/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:29:01 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/15 12:41:52 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen((char *)s1);
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = s1[len];
		len--;
	}
	return (str);
}
