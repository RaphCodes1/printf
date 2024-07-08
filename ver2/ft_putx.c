/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:07:51 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/08 19:08:44 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putx(unsigned long n, int base, char spec)
{
	char	*symbols;
	int		i;

	i = 0;
	if (spec == 'x')
		symbols = HEX_LOW_BASE;
	else if (spec == 'X')
		symbols = HEX_UP_BASE;
	if (n >= 16)
	{
		i += ft_putx(n / 16, base, spec);
		i += ft_putx(n % 16, base, spec);
	}
	else
		i += ft_putchar(symbols[n % base]);
	return (i);
}
