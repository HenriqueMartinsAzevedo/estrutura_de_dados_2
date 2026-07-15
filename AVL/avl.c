#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
    int altura;
} No;

//função para criar o no.
//essa função cria o no e por fim retorna o endereço de memória do no.
No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));

    if(novo == NULL) return NULL;

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 0;
    
    return novo;
}

// Compara as alturas da subárvore esquerda e da subárvore direita.
// Retorna a maior altura entre elas.
int maior(int a, int b){
    return (a > b) ? a : b;
}
