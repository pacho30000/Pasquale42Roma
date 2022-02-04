/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:42 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/04 05:45:46 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_check_after(t_flag *flag, int count)
{
    int len;
    int lim;

    len = 0;
    lim = count;
	if (flag->less_par == 0 && flag->plus == 1 && flag->space == 0 )
		count += ft_putchar('+');
	else if (flag->space == 1 && flag->less_par == 0
		&& (flag->type == 'd' || flag->type == 'i'))
		count += ft_putchar(' ');
    if (flag->less == 0 && flag->num > 0 || (flag->dot == 1 && flag->num > 0))
    {
        while (len < (flag->num - lim))
            len += ft_putchar('0');
    }
    if (flag->hastag == 1 && (flag->type == 'x' || flag->type == 'X'))
    {
        count += ft_putchar ('0');
        count += ft_putchar (flag->type);

    }
    if (flag->type == 'p')
    {
        write (1, "0x", 2);
        count += 2;
    }
    return (count + len);
}

int ft_check_before(t_flag *flag, int count, int nbr)
{
    int len;

    len = 0;
    if (flag->less == 1)
    {
        while (ft_l(nbr, 10, flag) < flag->num)
            len += ft_putchar(' ');
    }
    return (len);
}

int	ft_putnb(int long long nbr, char *base, int l_base, t_flag *flag)
{
	int	count;

    count = 0;
	if (nbr < 0)
		flag->less_par = 1;
    count = ft_check_after (flag, count);
	ft_putnbr_base(nbr, base, l_base, count);
    count += ft_check_before(flag, count, nbr);
	count += ft_l(nbr, l_base, flag);
	return (count);
}

void	ft_putnbr_base(int long long nbr, char *base, int l_base, int count)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base, l_base, count);
	}
    else if (nbr >= l_base)
	{
		ft_putnbr_base(nbr / l_base, base, l_base, count);
		ft_putchar(base[nbr % l_base]);
	}
	else if (nbr >= 0)
		ft_putchar(base[nbr % l_base]);
}