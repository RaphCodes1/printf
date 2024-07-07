#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// void ft_putchar(int c,int *count)
// {
//     write(1,&c,1);
//     (*count)++;
// }
// void ft_putstr(char *s, int *count)
// {   
//     if(!s)
//         s = "(null)";
//     while(*s)
//     {
//         ft_putchar(*s,count);
//         s++;
//     }
// }


// void print_format(char spec, va_list args,int *count)
// {
//     int i = 0;
//     if(spec == 's')
//     {
//         ft_putstr(va_arg(args, char *), count);
//     }
//     else if(spec == 'c')
//     {
//         ft_putchar(va_arg(args,int), count);
//     }
    
// }



// int ft_printf(char *spec, ...)
// {
//     int count;
//     int spec_count;
//     va_list args;

//     count = 0;
//     spec_count = 0;
//     va_start(args, spec);
//     while(*spec)
//     {   
//         if(*spec == '%')
//         {
//             print_format(*(++spec),args,&count);  
//         }
//         else
//             count += write(1,spec,1);
//         spec++;
//     }
//     va_end(args);
//     return (count);
// }
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_putstr(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	check(va_list args, const char c)
{
	ssize_t	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	ssize_t	len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += check(args, format[i]);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
int main()
{   
    int f = ft_printf("%s%s\n","Hello","hi");
    printf("my count: %d\n",f);

    int g = printf("%s%s\n","him ","hi");
    printf("orig count: %d\n",g);

}