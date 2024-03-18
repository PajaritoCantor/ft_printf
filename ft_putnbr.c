/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:27:48 by jurodrig          #+#    #+#             */
/*   Updated: 2024/03/09 20:19:09 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar('-') == -1)
				return (-1);
			n = -n;
			return (ft_putunbr (n) + 1);
		}
		return (ft_putunbr(n));
	}
}

Esta función escribe un número entero en la salida estandar
