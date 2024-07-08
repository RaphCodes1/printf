/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:11:42 by rcreer            #+#    #+#             */
/*   Updated: 2024/07/08 19:13:19 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int	ft_putx(unsigned long n, int base, char spec);
int	ft_uniputnbr(unsigned int nbr);
int	ft_putnbr(int nbr);
#endif