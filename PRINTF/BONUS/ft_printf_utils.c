/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:19:41 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/02 20:18:26 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_l(long nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_str_c(const char *str, int i, t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->type == 'c')
		count += ft_putchar(str[i]);
	else if (flag->type == 's')
	{
		while (str[i] != '%')
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	return (count);
}

int	ft_putchar(char lett)
{
	write(1, &lett, 1);
	return (1);
}

int long long	ft_put_b(int long long nbr, char *base, long l_base, t_flag *flag)
{
	int	count;

	count = ft_l(nbr, base);
	if (nbr < 0)
	{
		ft_putchar('-');
		flag->less = 1;
		ft_put_b(-nbr, base, l_base,flag);
	}
	else if (nbr >= l_base)
	{
		if (flag->less == 0 && flag->plus == 1)
		{
			write (1, '+', 1);
			count++;
		}
		ft_put_b(nbr / l_base, base, l_base, flag);
		ft_putchar(base[nbr % ft_len(base)]);
	}
	else if (nbr >= 0)
	{
		ft_putchar(base[nbr % l_base]);
	}
	return (count);
}

// + mette segno se positivo segno | PUO essere seguito da numero (0)
/* - mette spazi vuoti dopo il print
		| se n maggiore del count print
		| È sempre seguito da numero
		Funziona con - i, d, p, x, X, u
*/
/* 0 è un numero mette spazi vuoti prima del print
		| se n maggiore del print
		Funziona con - s, c, d, i, u, x, X, p
*/
/* space mette uno spazio vuoto se numero è positivo
		|PUO essere seguita da numero (0) 
		Funziona con - i, d, 
*/
/* . precision, scrive tanti zeri in base al numero che lo segue
		|solo se count è minore del numero
		Funziona con - s*, i, d, x, X
		*s -> se precision è minore della stringa scrive fino a quella lunghezza
*/
/* # aggiunge 0x prima del print
		Funziona solo con x, X
*/
int	ft_atoi(const char *str, int i, t_flag *flag)
{
	int	j;

	j = 0;
	flag->num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag->less = 1;
		else
			flag->plus = 1;
		i++;
	}
	if (str[i] == '.' || str[i] == ' ')
	{
		if (str[i] == '.')
			flag->dot = 1;
		else
			flag->space = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		flag->num = flag->num * 10 + (str[i++] - '0');
	j = flag->space + flag->dot + flag->less + flag->plus + ft_l(flag->num, 10);
	return (j);
}
