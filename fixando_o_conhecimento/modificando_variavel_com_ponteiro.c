#include <stdio.h>

int main(){
    
    int y = 25;
    int *p = &y;
    
    
    printf("Valor de 'y' -> %d\n", y);
    
    printf("Endereço de 'y' -> %p\n", p);
    
    printf("Conteúdo de 'y' -> %d\n", *p);
    
    printf("Endereço do ponteiro 'p' -> %p\n", &p);
    
    printf("========================================\n");
    printf("----- TROCANDO OS VALORES -----\n");
    printf("========================================\n");
    
    *p = 50;
    
    printf("Novo valor de 'y' -> %d", y);
    
    return 0;
}