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
