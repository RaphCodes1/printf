/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uniputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:09:12 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/08 19:09:40 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uniputnbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i += ft_uniputnbr(nbr / 10);
		i += ft_putchar(nbr % 10 + '0');
	}
	else
	{
		i += ft_putchar(nbr + '0');
	}
	return (i);
}
