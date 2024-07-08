#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
    int i;
    
    i = 0;

    while(s[i])
        i++;
    return(i);
}

int ft_putstr(char *s)
{   
    int i;

    i = 0;

    if(!s || s == NULL)
        s = "(null)";
    while(*s)
    {
        i += ft_putchar(*s);
        s++;
    }
    return (i);
    
    // return(write(1, s, ft_strlen(s)));
}