#include "ft_printf.c"

int main()
{   
    int f = 42;
    int i = ft_printf("%c\n%s\n%d\n%i\n%u\n%p\n%x\n%X\n", 'a', "Hello", -42, 24,420,&f,10000,10000); 
    // int d = ft_printf("%c%s", 'c',"Hello"); 
    printf("length of printf: \n%d\n",i);
}