#ifndef PRINTF_H
# define PRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>

# define HEX_UP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int ft_printf(const char *format, ...);
#endif