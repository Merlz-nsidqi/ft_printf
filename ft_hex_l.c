/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:30 by nsidqi            #+#    #+#             */
/*   Updated: 2023/11/17 17:24:51 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_l(unsigned long nb)
{
	int	c;

	c = 0;
	if (nb < 16)
	{
		c += ft_putchar("0123456789abcdef"[nb]);
		if (c == -1)
			return (-1);
	}
	else
	{
		if (c == -1)
			return (-1);
		c += ft_hex_l(nb / 16);
		c += ft_hex_l(nb % 16);
	}
	return (c);
}
