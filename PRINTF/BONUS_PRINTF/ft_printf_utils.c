/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:16:56 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/01 18:07:12 by pcatapan         ###   ########.fr       */
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

void	ft_atoi(const char *str, int i, t_flag *flag)
{
	int	num;

	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			flag->negative = 1;
			i++;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	if (str[i] != 'p')
	{
		flag->type = str[i];
		flag->space = num;
	}
	else
		flag->type = str[i];
}

void	ft_print_space(t_flag *flag)
{
	int	len;

	len = 0;
	while (len <= flag->space)
	{
		write (1, " ", 1);
		len++;
	}
}

int	ft_s(const char *str, t_flag *flag)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (flag->dot == 1)
	{
		while (str[i] && i < flag->space)
		{
			write (1, &str[i], 1);
			count++;
		}
	}
	else
	{
		while (str[i])
		{
			write (1, &str[i], 1);
			count++;
			i++;
		}
	}
	return (count);
}