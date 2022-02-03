/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:42 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/03 18:49:40 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_check_after(t_flag *flag, int count)
{
    int len;
    int ret;

    len = 0;
    ret = 0;
	if (flag->less_par == 0 && flag->plus == 1 && flag->space == 0 )
		ret += ft_putchar('+');
	else if (flag->space == 1 && flag->less_par == 0
		&& (flag->type == 'd' || flag->type == 'i'))
		ret += ft_putchar(' ');
    if (!flag->num || (flag->dot == 1 && !flag->num))
    {
        while (len < count && len < flag->num)
            len += ft_putchar('0');
    }
    if (flag->hastag == 1 && (flag->type == 'x' || flag->type == 'X'))
    {
        ret += ft_putchar ('0');
        ret += ft_putchar (flag->type);

    }
    ret = count + len;
    return (ret);
}

int ft_check_before(t_flag *flag, int count)
{
    int len;

    len = 0;
    if (flag->less == 1 && !flag->num)
    {
        while (len < count && len < flag->num)
            len += ft_putchar(' ');
    }
    return (len);
}

int	ft_putnb_b(int long long nbr, char *base, long l_base, t_flag *flag)
{
	int	count;

	count = ft_l(nbr, l_base, flag);
	if (nbr < 0)
	{
		count += ft_putchar('-');
		flag->less_par = 1;
		ft_putnb_b(-nbr, base, l_base,flag);
	}
	else if (nbr >= l_base)
	{
        count += ft_check_after (flag, count);
		ft_putnb_b(nbr / l_base, base, l_base, flag);
		ft_putchar(base[nbr % l_base]);
        count += ft_check_before(flag, count);
	}
	else if (nbr >= 0)
	{
		ft_putchar(base[nbr % l_base]);
	}
	return (count);
}
