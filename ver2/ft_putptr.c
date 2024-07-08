#include "ft_printf.h"

int ft_putptr(void *ptr)
{  
    int i;
    unsigned long long ptr_address; 

    i = 0;
    if(ptr == NULL || !ptr)
    {
        i += ft_putstr("0x0");
    }
    else
    {
        ptr_address = (unsigned long long)ptr;
        i += ft_putstr("0x");
        i += ft_putx(ptr_address,16,'x');
    }
    return (i);
}