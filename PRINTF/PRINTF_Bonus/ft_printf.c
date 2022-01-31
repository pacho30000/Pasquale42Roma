/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:00:24 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/31 20:18:57 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_space(const char *str, int i, t_flag *flag)
{
	if (str[i] == '+')
	{
		flag->negative = -1;
		i++;
	}
	if (str[i] == 32)
	{
		flag->space = 1;
		while (str[i] == 32)
			i++;
		if (str[i] == '-')
		{
			flag->negative = 1;
			i++;
		}
		flag->type = str[i];
		i++;
	}
	else
		ft_atoi(str, i, flag);
}

void	ft_start(const char *str, int i, t_flag *flag)
{
	int	count;

	count = 0;
	if ((str[i] > 47 && str[i] < 58) || str[i] == 45 || str[i] == 43
		|| str[i] == 32)
		ft_set_space(str, i, flag);
	else if (str[i] == 46)
	{
		flag->dot = 1;
		ft_atoi(str, i + 1, flag);
		i++;
	}
	else if (str[i] == 35)
	{
		i++;
		flag->hastag = 1;
		flag->type = str[i];
	}
	else
	{
		flag->type = str[i];
		i++;
	}
}

int	ft_string(const char *str, t_flag *flag)
{
	int	i;

	i = 0;
	//if (flag->dot == 1)
		while (str[i] != '%')
		{
			write (1, &str[i], 1);
			i++;
		}
	return (i);
}

int	ft_write_all(t_flag *flag, va_list var)
{
	int	count;

	count = 0;
	if (flag->type == 's')
		count += ft_string(va_arg(var, char *), flag);
	else if (flag->type == 'c')
		count += ft_char(va_arg(var, int));
	else if (flag->type == 'p')
		count += ft_esadecimal(va_arg(var, uintptr_t), flag);
	else if (flag->type == 'd' || flag->type == 'i')
		count += ft_putnumber(va_arg(var,int), flag);
	else if (flag->type == 'u')
		count += ft_unsigned(va_arg(var,unsigned int));
	else if (flag->type == 'x' || flag->type == 'X')
		count += ft_esadecimal(va_arg(var, unsigned int), flag);
	else if (flag->type == '%')
	{
		write(1, "%%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	var;
	t_flag	flag;
	int		i;
	int		count;

	i = 0;
	count = 0;
	flag.negative = 0;
	flag.dot = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] != '%' && str[i - 1] != '%')
		{
			count += ft_string(str, &flag);
			i += count;
		}
		if (str[i] == '%')
		{
			i++;
			ft_start(str, i, &flag);
			count += ft_write_all(&flag, var);
		}
		i++;
	}
	return (count);
}
