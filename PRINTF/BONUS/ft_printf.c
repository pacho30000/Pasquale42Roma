/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/04 05:02:50 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(t_flag *flag, va_list par)
{
	int	count;

	count = 0;
	if (flag->type == 's')
		count += ft_str_c(va_arg(par, char *), 0, flag);
	else if ( flag->type == 'c')
		count += ft_putchar(va_arg(par, int));
	else if (flag->type == 'd' || flag->type == 'i')
		count += ft_putnb(va_arg(par, int), "0123456789", 10, flag);
	else if (flag->type == 'x')
		count += ft_putnb(va_arg(par, unsigned int), "0123456789abcdef", 16, flag);
	else if (flag->type == 'X')
		count += ft_putnb(va_arg(par, unsigned int), "0123456789ABCDEF", 16, flag);
	else if (flag->type == 'p')
		count += ft_putnb(va_arg(par, uintptr_t), "0123456789abcdef", 16, flag);
	else if (flag->type == 'u')
		count += ft_putnb(va_arg(par, unsigned int), "0123456789", 10, flag);
	else if (flag->type == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_check(const char *str, int i, t_flag *flag)
{
	flag->dot = 0;
	flag->hastag = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->error = 0;
	flag->less = 0;
	i++;
	if (str[i] == '.' || str[i] == '-' || str[i] == '+' || str[i] == ' '
		|| (str[i] >= 0 && str[i] <= 9))
		i += ft_atoi(str, i, flag);
	else if (str[i] == '#')
		flag->hastag = 1;
	if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == 'X' || str[i] == '%')
		flag->type = str[i];
	else
	{
		write (1, "Errore : Flag non riconosciuta!", 31);
		flag->error = 1;
		return (31);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	par;
	t_flag	flag;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(par, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			count += ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			i = ft_check(str, i, &flag);
			if (flag.error == 1)
				return (31 + count);
			count += ft_write(&flag, par);
			i++;
		}
	}
	return (count);
}
