/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:43:49 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/22 01:44:29 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int used[255];

	i = 0;
	if (argc == 3)
	{
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!used[(unsigned char)argv[i][j]])
				{
					used[(unsigned char)argv[i][j]] = 1;
					write (1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
