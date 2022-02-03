/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/03 16:41:51 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(const char *str, int i, t_flag *flag, va_list par)
{
	int	count;

	count = 0;
	if (flag->type == 's' || flag->type == 'c')
		count += ft_str_c(va_arg(par, char *), 0, flag);
	else if (flag->type == 'd' || flag->type == 'i')
		count += ft_put_b(va_arg(par, int), "0123456789", 10, flag);
	return (count);
}

int	ft_check(const char *str, int i, t_flag *flag)
{
	flag->dot = 0;
	flag->hastag = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->less = 0;
	if (str[i] == '.' || str[i] == '-' || str[i] == '+' || str[i] == ' '
		|| (str[i] >= 0 && str[i] <= 9))
		i += ft_atoi(str, i, flag);
	else if (str[i] == '#')
		flag->hastag = 1;
	else if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == 'X')
		flag->type = str[i];
	else
	{
		write (1, "Errore : Flag non riconosciuta!", 31);
		return (0);
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
		while (str[i] != '%')
		{
			count += ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			i++;
			i += ft_check(str, i, &flag);
			flag.type = str[i];
			count += ft_write(str, i, &flag, par);
		}
	}
	return (count);
}
