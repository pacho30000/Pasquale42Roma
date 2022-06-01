/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:37:47 by pcatapan          #+#    #+#             */
/*   Updated: 2022/06/01 19:42:33 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_check_arguments(int argc, char **argv, t_main istance)
{
	i = 0;
	printf("%d\n", argc);
	if(argc != 5)
	{
		printf("Numero di argomenti errato!\n");
		return (0);
	}
	argument = (int *)malloc(sizeof(int) * (argc - 1));
	while (i != argc - 1)
	{
		argument[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	is
	return (0);
}