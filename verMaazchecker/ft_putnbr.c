/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:10:51 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/09 18:07:20 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		i += ft_putstr("-2147483648");
	else if (nbr < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(-nbr);
	}
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putchar(nbr % 10 + '0');
	}
	else
	{
		i += ft_putchar(nbr + '0');
	}
	return (i);
}
