/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:36:13 by nsidqi            #+#    #+#             */
/*   Updated: 2023/11/18 17:31:47 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char f, int c, va_list args)
{
	int		count;

	count = 0;
	if (f == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (f == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (f == '%')
		count = ft_putchar(f);
	else if (f == 'd' || f == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (f == 'u')
		count = ft_putunsnbr(va_arg(args, unsigned int));
	else if (f == 'p')
		count = ft_putptr(va_arg(args, void *));
	else if (f == 'x' || f == 'X')
		count = ft_hex(va_arg(args, unsigned int), f);
	else
	{
	}
	if (count < 0)
		return (-1);
	c += count;
	return (c);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		c;
	int		count;

	va_start(args, f);
	c = 0;
	while (*f)
	{
		if (*f == '%' && *(f + 1) != '\0')
		{
			f++;
			count = ft_format(*f, c, args);
			c = count;
		}
		else if (*f == '%' && *(f + 1) != '%')
		{
		}
		else
		{
			count = ft_putchar(*f);
			c += count;
		}
		if (count == -1)
			return (-1);
		f++;
	}
	va_end(args);
	return (c);
}
