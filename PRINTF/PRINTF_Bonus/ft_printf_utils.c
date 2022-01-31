/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:16:56 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/31 18:29:16 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_atoi(const char *str, int i, t_flag *flag)
{
	int	num;
	int	count;

	num = 0;
	count = 0;
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
		count += num;
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
