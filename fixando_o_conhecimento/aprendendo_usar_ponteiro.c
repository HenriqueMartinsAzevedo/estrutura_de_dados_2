#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x;
    
    
    
    printf("Valor de 'X' = %d\n", x);
    
    printf("Endereço de 'X' = %p\n", p);
    
    printf("Valor apontado por 'P' = %d\n", *p);
    
    printf("Endereço de 'P' = %p\n", &p);

    return 0;
}