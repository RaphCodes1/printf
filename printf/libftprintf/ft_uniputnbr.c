#include "ft_printf.h"

int ft_uniputnbr(unsigned int nbr)
{   
    int i;

    i = 0;
    if(nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
        i++;
    }
    else
    {
        ft_putchar(nbr + '0');
    }

    return (i);
}