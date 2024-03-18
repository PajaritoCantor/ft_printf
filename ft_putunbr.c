/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:31:37 by jurodrig          #+#    #+#             */
/*   Updated: 2024/03/09 20:30:46 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i = ft_putunbr(n / 10);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	i++;
	return (i);
}

- Esta función recursiva imprime un número entero sin signo
- Este bloqque de código verifica si n es mayor que 9.
* Si es así, la función se llama a sí misma con n/10 argumento
	* Esto divide n por 10 para eliminar el último dígito. El resultado de esta llamada recursiva se asigna a i. Si i es -1, la función retorna -1
- Esto se hace para manejar errores en la llamada recursiva
- El siguiente bloque de código llama a la función ft_putchar con n%10 + '0' como argumento
- Esto calcula el residuo de n dividido por 10 (el último dígito de n) y luego lo convierte en un carácter al sumarle '0'
Si ft_putchar retorna -1, la función retorna -1. Esto se hace para manejar errores en la llamada a ft_putchar
