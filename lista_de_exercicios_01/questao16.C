#include <stdlib.h>
#include <stdio.h>

//--------------------------
//Estrutura do nó
//--------------------------
typedef struct No{
    int valor;
    struct No *primeiro_filho; //Aponta para o nó mais a esquerda
    struct No *prox_irmao; //Aponta para o nó a direita.
}No;

int main(){
    return 0;
}