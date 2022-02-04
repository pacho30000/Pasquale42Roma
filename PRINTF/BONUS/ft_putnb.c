/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:42 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/04 19:53:29 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_before(t_flag *flag, int count)
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
    if (flag->less_par == 1 && (flag->zero == 1 || flag->dot == 1))
        ft_putchar('-');
    if (flag->type != 'p' && ((flag->less == 0 && flag->num > 0 && flag->zero == 1)))
    {
        while (len < (flag->num - lim))
            len += ft_putchar('0');
    }
    if (flag->dot == 1 && flag->num > 0)
    {
        while (len < (flag->num - lim + flag->less_par))
            len += ft_putchar('0');
    }
    else if (flag->num >= 0 && flag->less == 0 && flag->hastag == 0)
    {
        if (flag->type == 'p')
        {
            while (len < (flag->num - lim - 2))
                len += ft_putchar(' ');
        }
        else
        {
        while (len < (flag->num - lim))
                len += ft_putchar(' ');
       }
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

int ft_check_after(t_flag *flag, int count)
{
    int len;

    len = 0;
    if (flag->less == 1)
    {
        while (len < (flag->num - count))
            len += ft_putchar(' ');
    }
    return (len);
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

int	ft_putnb(int long long nbr, char *base, int l_base, t_flag *flag)
{
	int	count;

    count = 0;
	if (nbr < 0)
		flag->less_par = 1;
	if (nbr < 0 && (flag->zero == 1 || flag->dot == 1))
        nbr = nbr * -1;
    if (flag->hastag == 1 && nbr == 0)
        flag->hastag = 0;
	count += ft_l(nbr, l_base, flag) + flag->less_par;
    count = ft_check_before (flag, count);
	ft_putnbr_base(nbr, base, l_base, count);
    count += ft_check_after(flag, count);
	return (count);
}
