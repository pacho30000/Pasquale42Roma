/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:31:31 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/03 18:51:06 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	t;

	t = 0;
	printf("\n%d", printf("%c " , '0'));
	printf("\n\n");
	//printf("%.2s" , "aaa");
	ft_printf("\n%d", ft_printf("%c " , '0'));
	return (0);
}