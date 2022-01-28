/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putesa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:37:15 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/28 03:34:12 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digitesa(int nb)
{
	unsigned long long	n;

	while (nb > 0)
	{
		n = (nb % 10) + '0';
		write (1, &n, 1);
		nb = nb / 16;
	}
}

int	ft_lenesa(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putesa(uintptr_t num)
{
	int	count;

	count = ft_lenesa(num);
	ft_digitesa(num);
	return (count);
}
