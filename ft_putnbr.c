/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:15:38 by nsidqi            #+#    #+#             */
/*   Updated: 2023/11/16 15:23:49 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr(long int nb, int c)
{
	int	div;
	int	digit;

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

int	ft_putnbr(int n)
{
	long int	nb;
	int			c;

	c = 0;
	nb = n;
	if (nb < 0)
	{
		c = ft_putchar('-');
		nb = -nb;
		if (c == -1)
			return (-1);
	}
	return (ft_nbr(nb, c));
}
