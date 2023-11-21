/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:30 by nsidqi            #+#    #+#             */
/*   Updated: 2023/11/16 18:53:50 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num(unsigned int nb)
{
	int	r;

	r = 0;
	while (nb)
	{
		nb = nb / 10;
		r++;
	}
	return (r + 1);
}

static char	*ft_less(unsigned int nb, char f)
{
	int		i;
	int		digit;
	char	*d;

	i = 0;
	d = malloc(sizeof(char) * ft_num(nb));
	if (d == NULL)
		return (NULL);
	while (nb > 0)
	{
		digit = nb % 16;
		if (f == 'x')
			d[i++] = "0123456789abcdef"[digit];
		else
			d[i++] = "0123456789ABCDEF"[digit];
		nb /= 16;
	}
	d[i] = '\0';
	return (d);
}

int	ft_hex(unsigned int nb, char f)
{
	int		c;
	int		i;
	char	*d;

	c = 0;
	if (nb == 0)
	{
		c = ft_putchar('0');
		return ((c != -1) - (c == -1));
	}
	d = ft_less(nb, f);
	if (d == NULL)
		return (-1);
	i = ft_strlen(d) - 1;
	while (i >= 0)
	{
		c += ft_putchar(d[i--]);
		if (c == -1)
		{
			free(d);
			return (-1);
		}
	}
	free(d);
	return (c);
}
