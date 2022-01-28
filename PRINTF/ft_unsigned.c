/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:54:08 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/27 23:53:50 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digitunsi(unsigned long num)
{
	int	n;

	while (num > 0)
	{
		n = (num % 10) + 48;
		write (1, &n, 1);
		num = num / 10;
	}
}

unsigned int	ft_lenunsi(unsigned long num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned long num)
{
	int	count;

	count = ft_lenunsi(num);
	ft_digitunsi(num);
	return (count);
}
