/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 08:12:07 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/20 05:18:54 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_can_move(char c)
{
	int		i;
	char	*elm;

	i = 0;
	elm = (char *)malloc(sizeof(char) * 3 + 1);
	elm[0] = '1';
	elm[1] = 'N';
	elm[2] = 'E';
	elm[3] = '\0';
	while (elm[i] != '\0')
	{
		if (elm[i] == c)
		{
			free(elm);
			return (0);
		}
		i++;
	}
	free(elm);
	return (1);
}
