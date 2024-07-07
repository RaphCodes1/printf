#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    unsigned long ptr_address;

    ptr_address = (unsigned long)ptr;
    write(1,"0x",2);
    ft_putx(ptr_address,16,'x');

    return (1);
}