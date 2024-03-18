/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:48:11 by jurodrig          #+#    #+#             */
/*   Updated: 2024/03/17 04:48:27 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_pointer(unsigned long p)
{
	int	result;
	int	hex;

	result = ft_putstr("0x");
	if (result == -1)
		return (-1);
	hex = ft_putnbr_base(p, "0123456789abcdef", 0);
	if (hex == -1)
		return (-1);
	return (result + hex);
}

- Esta función toma un puntero representado como un número entero sin signo como argumento y lo imprime en formato hexadecimal
- La función ft_putstr se utiliza para imprimir la cadenaa "0x", que es el prefijo estándar para los números hexadecimales
* Si ft_putstr devuelve -1, significa que hubo un error, por lo que la función ft_hex_pointer también devuelve -1
- La función ft_putnbr_base se utiliza para convertir el número p a una cadena hexadecimal y la imprime. Si ft_putnbr_base devuelve -1
	* Significa que hubo un error, por lo que la función ft_hex_pointer también devuelve -1.


int	ft_check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_hex_pointer(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", 0));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 0));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_format(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (*(format + *i) == '%' && *(format + *i + 1) != '\0')
	{
		(*i)++;
		count = ft_check_format(*(format + *i), args);
		if (count == -1)
			return (-1);
	}
	else if (*(format + *i) != '%')
	{
		count = ft_putchar(*(format + *i));
		if (count == -1)
			return (-1);
	}
	(*i)++;
	return (count);
}
- Esta función procesa una cadena de formato y una lista de argumentos para formateaar una salida
	* Un puntero a una cadena de caracteres que contiene el formato de salida deseado. Los especificadores de formato son introducidos por el caráacter %.
	* Una lista de argumentos que se pasan a la función. Estos argumentos son los valores que se insertarán en la caadena de formato en los luigaares especificadores de formato
	* Un puntero a un entero que se utiiza para rastreaar la posición actual en la cadena de formato
- El primer bloque de codigo se ejecuta si el carácter en la posicón i de formato es un % y el siguiente carácter no es el carácter nulo
- si es así incrementa i y luego llama a la función ft_check_format con el carácter en la nueva posición i de format y args
- Este bloque de código se ejecuta si el carácter en la posición i de format no es un %. Si es así, llama a la función i de format y asigna el resultado a count.

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		result;

	va_start(args, format);
	i = 0;
	count = 0;
	result = 0;
	if (format)
	{
		while (*(format + i))
		{
			result = ft_format(format, args, &i);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
		}
	}
	va_end(args);
	return (count);
}
- Esta función es una implementación personalizada de la función printf
- Toma una cadena de formato y un número variable de argumentos. Formatea los argumentos según la cadena de formato y los imprime en la salida estandar retornando el número total de caaracteres impresos
	* Si ocurre un error durante el formateo la función retorna -1
- El bloque recorre la cadena de formato y llama a la función ft_format devuelve -1, se termina la lista de argumentos con va_end y se retornma -1. De lo contrario se suma el resultado de ft_format.
- Finalmente la lista de argumentos args se limpia con va_end. La función devuelve count que es el número total de caracteres impresos

/*
#include <stdio.h>

int main(void)
{
    char *str = "Hola, mundo!";
    int num = 42;
    unsigned int unum = 42;
    void *ptr = &num;
	int len;

    ft_printf("Imprimiendo un solo carácter: %c\n", 'A');
    ft_printf("Imprimiendo una cadena: %s\n", str);
    ft_printf("El puntero void * dado como argumento se imprime en formato hexadecimal: %p\n", ptr);
    ft_printf("Imprimiendo un número decimal (base 10): %d\n", num);
    ft_printf("Imprimiendo un entero en base 10: %i\n", num);
    ft_printf("Imprimiendo un número decimal (base 10) sin signo: %u\n", unum);
    ft_printf("Imprimiendo un número hexadecimal (base 16) en minúsculas: %x\n", num);
    ft_printf("Imprimiendo un número hexadecimal (base 16) en mayúsculas: %X\n", num);
    ft_printf("Imprimiendo el símbolo del porcentaje: %%\n");

	ft_printf("hola soy %s, y tengo %d años.\n", "Marvin", 42) ;
	
    return 0;
}
*/
