#include "ft_printf.h"
#include <stdio.h>

int print_char(int c)
{  
    write(1,&c,1);
    return (1);
    
}

int print_string(char *s)
{   
    int i;

    i = 0;
    while(*s)
    {
        print_char(*s);
        i++;
    }
    return (i);
}

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
char *ft_itoa(int n)
{
    int len;
    char *num;
    char *res;

    if (n == -214748364 - 1)
		return ("-2147483648");
    num = "0123456789";
    len = ft_numlen(n);
    res = (char *)malloc(sizeof(char) * (len + 1));
    if(!res)
        return (NULL);
    res[len] = '\0';
    if(n < 0)
    {
        res[0] = '-';
    }  
    if(n == 0)
    {
        res[0] = '0';
    }

    while(n)
    {   
        if(n > 0)
        {
            res[--len] = num[n % 10];
        }
        else
        {
            res[--len] = num[n % 10 * -1];
        }
        n /= 10;
    }
    return (res);
}
int print_num(int n)
{   
    char *res;
    int i;

    i = 0;
    res = ft_itoa(n);

    while(*res)
    {
        write(1,res,1);
        ++res;
        ++i;
    }
    return (i);
    
}

int print_u(unsigned int n)
{   
    char *str;
    int i;

    i = 0;
    str = ft_itoa(n);
    while(*str)
    {
        write(1,str,1);
        str++;
        i++;
    }
    return (i);
}

long print_x(unsigned long n,int base,char spec)
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

int print_ptr(void *ptr)
{
    unsigned long ptr_address;

    ptr_address = (unsigned long)ptr;
    write(1,"0x",2);
    print_x(ptr_address,16,'x');

    return (1);
}
int print_format(char specifier, va_list ap)
{
    int count;

    count = 0;
    if(specifier == 'c')
    {
        count += print_char(va_arg(ap,int));
    }
    else if(specifier == 's')
    {
        count += print_string(va_arg(ap,char *));
    }
    else if(specifier == 'd' || specifier == 'i')
    {
        count += print_num(va_arg(ap,int));
    }
    else if(specifier == 'x' || specifier == 'X')
    {
        count += print_x(va_arg(ap,unsigned int),16,specifier);
    }
    else if(specifier == 'p')
    {
        count += print_ptr(va_arg(ap,void *));
    }
    else if(specifier == 'u')
    {
        count += print_u(va_arg(ap, unsigned int));
    }
    else
    {
        count += write(1,&specifier,1);
    }
    return(count);
}
int ft_printf(const char *format,...)
{
    va_list ap;
    int i;

    i = 0;

    va_start(ap, format);
    while(*format)
    {   
        if(*format == '%')
            i += print_format(*(++format), ap);
        else
            i += write(1,format,1);
        format++;
    }
    va_end(ap);
    return (i);
}

int main()
{
    int i = ft_printf("%c%c%c", 'a', 'c', 'b'); 
    printf("\n%d\n",i);
}
