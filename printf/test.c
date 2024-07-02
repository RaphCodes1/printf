#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int print_char(int n)
{
    return write(1,&n,1);
}

int print_string(char *s)
{
    int i;

    i = 0;
    while(*s)
    {
        write(1,s,1);
        s++;
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
    
int print_check(char check,va_list ap)
{
    int i;

    i = 0;
    if(check == 'c')
    {
        i += print_char(va_arg(ap,int));
    }
    else if(check == 's')
    {
        i += print_string(va_arg(ap,char *));
    }
    else if(check == 'd')
    {
        i += print_num(va_arg(ap,int));
    }
    else
    {
        i += write(1,&check,1);
    }
    return (i);
}
int ft_printf(const char *format,...)
{
    int i;
    va_list ap;
    i = 0;

    va_start(ap,format);
    while(*format)
    {
        if(*format == '%')
            i += print_check(*(++format),ap);
        else
            i += write(1,format,1);
        ++format;
    }
    va_end(ap);
    return(i);
}
int main(void)
{
    int i = 42;

    ft_printf("%d\n",i);

    for(int i = 0; i < 10; ++i)
    {
        printf("%d\n",i);
    }

    
   
}