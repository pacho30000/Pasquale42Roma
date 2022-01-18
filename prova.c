/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:09:05 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/18 21:16:16 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		l;
	char				*str;
	unsigned int		i;

	if (!s)
		return (NULL);
	l = ft_strlen((char *)s);
	if (l < len)
		str = (char *)malloc(l * sizeof(char) + 1);
	else
		str = (char *)malloc(len * sizeof(char) + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i <= l && len > 0 && start <= l)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_countarray(char const *s, char c)
{
	int	i;
	int	array;

	i = 0;
	array = 0;
	if (!s)
		return(0);
	while (s[i])
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
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
	str = malloc(array * sizeof(char) + 1);
	if (!str || str == 0)
		return (NULL);
	while (s[i] && j != array)
	{
		while (s[i++] == c)
			start = i;
		while (s[i] != c)
			i++;
		str[j] = malloc(i - start * sizeof(char) + 1);
		str[j++] = ft_substr(s, start, i - start);
	}
	str[j] = NULL;
	return (str);
}

int        main(void)
{
    int i = 0;
    char **tab;
        
    tab = ft_split("        ", ' ');
    while (i < 2)
    {
        printf("string %d : %s\n", i, tab[i]);
        i++;
    }
    return (0);
}
