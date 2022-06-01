/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:01:56 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/04 18:01:57 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digitu(unsigned int nb)
{
	int	n;

	if (nb >= 10)
	{
		ft_digitu(nb / 10);
		n = (nb % 10) + 48;
		write(1, &n, 1);
	}
	if (nb >= 0 && nb < 10)
	{
		n = nb + 48;
		write(1, &n, 1);
	}
}

unsigned int	ft_lenu(unsigned int nb)
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

int	ft_u(unsigned int num)
{
	int	count;

	count = ft_lenu(num);
	ft_digitu(num);
	return (count);
}
