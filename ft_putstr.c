/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:00:55 by nsidqi            #+#    #+#             */
/*   Updated: 2023/11/16 08:45:05 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	c;

	i = 0;
	if (s == NULL)
	{
		c = write(1, "(null)", 6);
		if (c == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		c = write(1, &s[i], 1);
		if (c == -1)
			return (-1);
		i++;
	}
	return (i);
}
