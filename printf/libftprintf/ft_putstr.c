#include "ft_printf.h"

int ft_putstr(char *s)
{   
    int i;

    i = 0;
    while(*s)
    {
        ft_putchar(*s);
        i++;
        s++;
    }
    return (i);
}