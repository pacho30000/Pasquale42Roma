/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:05:33 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/12 15:20:42 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  strlcat(char *dst, const char *src, size_t destsize)
{
    size_t  i;
    size_t  j;
    size_t  x;
    
    i = 0;
    while (dst[i] != '\0')
        i++;
    j = 0;
    while (src[j] != '\0')
        j++;
    x = 0;
    if (destsize <= i)
        x = j + destsize;
    else
        x = j + i;
    j = 0;
    while (src[j] != '\0' && i + 1 < destsize)
    {
        dst[i++] = src[j++];
    }
    dst[i] = '\0';
    return (x);
}
