#include "ft_printf.h"

int ft_putnbr(int nbr)
{   
    int i;

    i = 0;
    if(nbr == -2147483647 - 1)
        ft_putstr("-2147483648");
    if(nbr < 0)
    {
        ft_putchar('-');
        ft_putnbr(-nbr);
    }
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