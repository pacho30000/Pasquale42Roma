/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:48:05 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/22 01:54:46 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	used[255];

	i = 0;
	while (i < 255)
		used[i++] = 0;
	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && used[(unsigned char)argv[1][i]] == 0)
				{
					used[(unsigned char)argv[1][i]] = 1;
					write (1, &argv[1][i], 1);
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
