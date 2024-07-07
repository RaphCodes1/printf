#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

# define HEX_UP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int ft_printf(const char *format, ...);
int ft_putchar(int c);
int ft_putstr(char *s);
int ft_putptr(void *ptr);
long ft_putx(unsigned long n,int base,char spec);
int ft_uniputnbr(unsigned int nbr);
int ft_putnbr(int nbr);
#endif