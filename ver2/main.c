#include "ft_printf.c"
#include <stdio.h>
#include <limits.h>

int main()
{   
    // int f = 42;
    // int i = ft_printf("%c\n%s\n%d\n%i\n%u\n%p\n%x\n%X\n", 'a', "Hello", -42, 24,420,&f,10000,10000); 
    // // int d = ft_printf("%c%s", 'c',"Hello"); 
    // printf("length of printf: \n%d\n",i);
    // int i = printf(" NULL %s NULL\n", NULL);
    // int f = ft_printf(" NULL %s NULL\n", NULL);
    // printf("orig: %d\n own: %d\n",i,f);
    // int i = ft_printf("%p", "");
    // ft_printf("\n%d",i);
    // printf("\n%d\n",i);

    // printf("%s%","Hello","There");


    int i = ft_printf("my - hello %x\n", -1);
    printf("%d\n", i);
    int j = printf("fn - hello %x\n", -1);
    printf("%d\n", j);

}