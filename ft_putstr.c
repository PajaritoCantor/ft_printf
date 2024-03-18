/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 06:56:44 by jurodrig          #+#    #+#             */
/*   Updated: 2024/03/09 20:28:47 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[count])
	{
		if (ft_putchar(s[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

- Esta función toma un puntero a una cadena de carácteres char *s como argumento
- El primer bloque bloque comprueba si el puntero S es nulo. Si es así, la función se llama a así misma con la cadena "null" y devuelve el resultado de esa llamada
- El segundo bloque es un bucle que recorre cada caráacter de la cadena s. 
	* Para cada carácter, llama a la función ft_putchar para escribir el carácter. 
	* Si ft_putchar devuelve -1, entonces ft_putstr también devuelve -1. Después de procesar cada caracter, incrementa count
