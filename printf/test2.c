#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count(int n)
{
    int i;

    i = 0;
    if(!n)
        return (i);
    else
    {
        i = count(n / 10);
        return i + 1;
    }
        
}
char *display_x(unsigned int n)
{   
    int size;
    char *symbols;
    char *res;

    size = count(n);
    symbols = "0123456789abcdef";
    res = malloc(sizeof(char *) * (size + 1));
    if(!res)
        return NULL;
    res[size] = '\0';
    // res[0] = '0';
    while(n)
    {
        res[--size] = symbols[n % 16];
        n /= 16;
    }

    return (res);
}


void	ft_putnbr_pf(int num)
{
	if (num == -2147483648)
	{
		ft_putnbr_pf((num / 10));
		printf("Check: %c\n",'8');
	}
	else if (num < 0)
	{
		printf("%c Check:",'-');
		ft_putnbr_pf(-num);
	}
	else
	{
		if (num > 9)
			ft_putnbr_pf((num / 10));
		printf("%d",(num % 10));
	}
}

int main (void)
{   
    int i = -2147483648;
    ft_putnbr_pf(i);
}