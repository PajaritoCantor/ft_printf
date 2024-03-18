/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:20:19 by jurodrig          #+#    #+#             */
/*   Updated: 2024/03/09 20:25:50 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base, int result)
{
	unsigned long	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr < len_base)
	{
		if (ft_putchar(base[nbr]) == -1)
			return (-1);
		return (result + 1);
	}
	else
	{
		result = ft_putnbr_base(nbr / len_base, base, result);
		if (result == -1)
			return (-1);
		if (ft_putchar(base[nbr % len_base]) == -1)
			return (-1);
		return (result + 1);
	}
}

Esta función imprime un número en una base dada
- Toma un número sin signo nbr, una cadena base que representa la base en la que se imprimirá el número, y un entero result que representa el número de caracteres impresos hasta ahora
- El primer bloque calcula la longitud de la cadena base y la almacena en len_base
- Si nbr es menor que len_base, entonces se imprime el carácter en la posición nbr de la cadena base usando la función ft_putchar
- Si ft_putchar devuelve -1, la función ft_putnbr_base también devuelve -1, si no, devuelve -1. Si no, devuelve result + 1
- Si nbr no es menor que len_base, entonces se llama a la función ft_putnbr_base de forma recursiva con nbr/len base como primer argumento
* Si la llamada recursiva devuelve -1, la función ft_putnbr_base también devuelve -1
- Luego se imprime el caarácter en la nbr% len_base de la cadena base usando la función ft_putchar
* si ft_putchar devuelve -1, la función ft_putnbr_base también devuelve -1, si no, devuelve result +1
