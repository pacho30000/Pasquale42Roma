/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:48:52 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/31 20:15:30 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	char	type;
	int		space;
	int		negative;
	int		dot;
	int		hastag;
}	t_flag;


int				ft_printf(const char *str, ...);
int				ft_char(char lett);
int				ft_putesa(uintptr_t num);
unsigned int	ft_esadecimal(unsigned int num, t_flag *flag);
int				ft_putnumber(int num, t_flag *flag);
int				ft_unsigned(unsigned int num);
void			ft_print_space(t_flag *flag);
void			ft_atoi(const char *str, int i, t_flag *flag);

#endif