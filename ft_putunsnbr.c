/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:15:38 by nsidqi            #+#    #+#             */
/*   Updated: 2023/11/16 11:47:04 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr(unsigned int n)
{
	long int	nb;
	int			c;
	long int	div;
	int			digit;

	c = 0;
	nb = n;
	div = 1;
	while (nb / div > 9)
		div *= 10;
	while (div > 0)
	{
		digit = nb / div;
		c += ft_putchar(digit + '0');
		if (c == -1)
			return (-1);
		nb %= div;
		div /= 10;
	}
	return (c);
}
