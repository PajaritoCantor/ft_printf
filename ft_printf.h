/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:37:48 by jurodrig          #+#    #+#             */
/*   Updated: 2024/03/09 21:05:39 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_putnbr_base(unsigned long nbr, char *base, int result);
int		ft_printf(const char *str, ...);
int		ft_format_processor(char format, va_list args);
int		ft_hex_pointer(unsigned long p);
int		ft_check_format(const char *format, va_list args, int *i);

#endif
