/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esadecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:01:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/28 00:14:49 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digitupper(unsigned int nb)
{
	unsigned long long	n;

	while (nb > 0)
	{
		n = nb % 10;
		if (n >= 'a' && n <= 'z')
			n = n - 20;
		n = n + '0';
		write (1, &n, 1);
		nb = nb / 16;
	}
}

static void	ft_digitlower(unsigned int nb)
{
	unsigned long long	n;

	while (nb > 0)
	{
		n = nb % 10;
		if (n >= 'A' && n <= 'Z')
			n = n + 20;
		n = n + '0';
		write (1, &n, 1);
		nb = nb / 16;
	}
}

unsigned int	ft_esadecimal(unsigned int num, char lett)
{
	int	count;

	count = ft_lenesa(num);
	if (lett == 'X')
		ft_digitupper(num);
	ft_digitlower(num);
	return (count);
}
