/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:31:35 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/15 20:21:07 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	ft_abs(int n)
{
	if (n > 9)
		n = n / 10;
	return (n);
}
*/

int	ft_len(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		s;

	len = 1;
	s = 0;
	if (!n)
		return (0);
	if (n < 0)
	{
		s = 1;
		n *= - 1;
	}
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * len + 1 + s);
	if (!str)
		return (NULL);
	if (s == 1)
		*str = '-';
	while (n >= 0)
	{
		n = n / 10;
		*++str = n + 48;
	}
	*++str = '\0'; 
	return (str);	
}
 