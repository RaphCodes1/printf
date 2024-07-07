#include "ft_printf.h"

int ft_numlen(int n)
{
    int i;

    i = 0;
    if(n <= 0)
        i++;
    while(n)
    {
        i++;
        n /= 10;
    }
    return (i);
}
long ft_putx(unsigned long n,int base,char spec)
{
    int size;
    char *symbols;
    char *res;

    size = ft_numlen(n);
    if(spec == 'x')
        symbols = HEX_LOW_BASE;
    else if(spec == 'X')
        symbols = HEX_UP_BASE;
    res = malloc(sizeof(char *) * (size + 1));
    if(!res)
        return (0);
    res[size] = '\0';
    while(n)
    {
        write(1,&symbols[n % base],1);
        n /= base;
    }

    return (1);
}