/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:49:40 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/01 19:22:26 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	s;
	size_t	num;

	i = 0;
	num = 0;
	s = 1;
	while(str[i] != '\0')
	{
		if(str[i] < '0' && str[i] > '9')
		{
			printf("Argomento non Valido!");
			return (0);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}