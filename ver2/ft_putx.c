#include "ft_printf.h"

// unsigned int ft_numlen16(unsigned int n)
// {
//     int i;

//     i = 0;
//     if(n <= 0)
//         i++;
//     while(n)
//     {
//         i++;
//         n /= 16;
//     }
//     return (i);
// }
int ft_putx(unsigned long n,int base,char spec)
{
    char *symbols;
    int i;

    i = 0;
    if(spec == 'x')
        symbols = HEX_LOW_BASE;
    else if(spec == 'X')
        symbols = HEX_UP_BASE;
    if(n >= 16)
    {
        i += ft_putx(n / 16, base, spec);
        i += ft_putx(n % 16, base, spec);
    }
    else
        i += ft_putchar(symbols[n % base]);
        
    return (i);
}