/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:01:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/05/04 18:01:39 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_char(int lett);
unsigned int	ft_lenu(unsigned int num);
int				ft_u(unsigned int num);
unsigned int	ft_esa(unsigned int num, char lett);
int				ft_putnbr(int num);
int				ft_lenesa(uintptr_t nb);
int				ft_putesa(uintptr_t num);

#endif
