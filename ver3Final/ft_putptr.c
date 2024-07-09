/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:10:19 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/08 19:10:47 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int					i;
	unsigned long long	ptr_address;

	i = 0;
	if (ptr == NULL || !ptr)
	{
		i += ft_putstr("0x0");
	}
	else
	{
		ptr_address = (unsigned long long)ptr;
		i += ft_putstr("0x");
		i += ft_putx(ptr_address, 16, 'x');
	}
	return (i);
}
