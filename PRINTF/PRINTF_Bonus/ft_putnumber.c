/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:23:20 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/31 18:29:22 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_digit(long nb, t_flag *flag)
{
	int	n;

	if (flag->space == 1)
	{
		write (1, " ", 1);
		flag->space = 0;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write (1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_digit(nb / 10, flag);
		n = (nb % 10) + 48;
		write (1, &n, 1);
	}
	if (nb >= 0 && nb < 10)
	{
		n = nb + 48;
		write (1, &n, 1);
	}
}

static int	ft_len(long nb, t_flag *flag)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnumber(int num, t_flag *flag)
{
	int		count;
	long	nb;

	nb = num;
	count = ft_len(nb, flag);
	count = count + flag->space + flag->negative; 
	ft_digit(nb, flag);
	if (flag->negative == 1)
		ft_print_space(flag);
	return (count);
}
