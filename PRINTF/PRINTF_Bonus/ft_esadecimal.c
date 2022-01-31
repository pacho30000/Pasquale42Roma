/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esadecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:01:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/31 20:15:45 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenesa(uintptr_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

static void	ft_digit(unsigned int nb, char *base, t_flag *flag, int len)
{
	int	diff;

	diff = 0;
	if (flag->space > len && flag->dot == 1)
	{
		diff = flag->space - len;
		while (diff > 0)
		{
			write(1, "0", 1);
			diff--;
		}
		flag->dot = -1;
	}
	if (nb >= 16)
	{
		ft_digit(nb / 16, base, flag, len);
		ft_char(base[nb % 16]);
	}
	else if (nb >= 0)
	{
		ft_char(base[nb % 16]);
	}
}

unsigned int	ft_esadecimal(unsigned int num, t_flag *flag)
{
	int	count;

	count = ft_lenesa(num);
	if (flag->hastag == 1 && flag->type != 'p')
	{
		write (1, "0", 1);
		write (1, &flag->type, 1);
		count += 2;
	}
	if (flag->type == 'p')
	{
		write (1, "0x", 2);
		count += 2;
		ft_digit(num, "0123456789abcdef", flag, count);
	}
	else if (flag->type == 'X')
		ft_digit(num, "0123456789ABCDEF", flag, count);
	else if (flag->type == 'x')
		ft_digit(num, "0123456789abcdef", flag, count);
	if (flag->dot == -1 && flag->space > count)
		count += flag->space - count;
	return (count);
}
