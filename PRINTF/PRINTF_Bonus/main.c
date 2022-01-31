/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:31:31 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/31 20:17:31 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	t;

	t = 0;
	printf("\n%d", printf("%.2s" , "aaa"));
	printf("\n\n");
	printf("%.2s" , "aaa");
	//printf("\n%d", ft_printf("%.10x", -1));
	return (0);
}