/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:38:30 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/19 22:59:58 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countarray(char const *s, char c)
{
	int	i;
	int	array;

	i = 0;
	array = 0;
	if (!s)
		return (0);
	if (s[i] && s[i] != c)
		array++;
	if (s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			array++;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	array;
	size_t	start;
	char	**str;

	j = 0;
	i = 0;
	array = ft_countarray(s, c);
	str = malloc((array + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	while (s[i] && j < array)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str[j] = ft_substr(s, start, i - start);
		j++;
	}
	str[j] = NULL;
	return (str);
}

int main()
{
	char **porco;

	porco = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	printf("%s", porco[0]);
	return (0);
}
