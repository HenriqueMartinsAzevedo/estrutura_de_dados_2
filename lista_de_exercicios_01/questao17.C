#include <stdlib.h>
#include <stdio.h>

//--------------------------
//Estrutura do nó
//--------------------------
typedef struct No{
    int valor;
    struct No *prim_filho; //Aponta para o nó mais a esquerda
    struct No *prox_irmao; //Aponta para o nó a direita.
}No;

//--------------------------
//Inicializar uma árvore vazia
//--------------------------
No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prim_filho = NULL; // NULL é para receber um valor vazio, garantindo que não irá receber "Lixo de memória"
    novo->prox_irmao = NULL;

    return novo;
}

int main(){
    return 0;
}