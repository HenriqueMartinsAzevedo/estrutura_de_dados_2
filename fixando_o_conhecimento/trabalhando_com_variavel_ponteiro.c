#include <stdio.h>

void trocar(int *p1, int *p2){
    int aux = 0;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}
int main()
{
    int a = 5;
    int b = 10;
    
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   
   trocar(&a, &b);
   
   printf("a = %d\n", a);
   printf("b = %d\n", b);
    return 0;
}