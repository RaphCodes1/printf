/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:08:48 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/09 18:07:00 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_putx(va_arg(ap, unsigned int), 16, specifier);
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (specifier == 'u')
		count += ft_uniputnbr(va_arg(ap, unsigned int));
	else if (specifier == '%')
		count += ft_putchar('%');
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		checker;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		checker = i;
		if (*format == '%')
			i += print_format(*(++format), ap);
		else
			i += ft_putchar(*format);
		if (checker > i)
			return (-1);
		format++;
	}
	va_end(ap);
	return (i);
}
