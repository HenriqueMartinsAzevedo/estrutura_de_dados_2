#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//--------------------------
//Estrutura do nó
//--------------------------

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    
    return novo;
}

//-------------------------------------
//Inserção por nível (não ordenado)
//-------------------------------------

No* inserir(No* raiz, int valor) {
    No* novo = criarNo(valor);
    
    No* fila[MAX];
    int inicio = 0, fim = 0;

    fila[fim++] = raiz;

    while(inicio < fim) {
        No* atual = fila[inicio++];

        if(atual->esq == NULL) {
            atual->esq = novo;
            return raiz;
        }

        else {
            fila[fim++] = atual->esq;
        }

        if (atual->dir == NULL) {
            atual->dir = novo;
            return raiz;
        }

        else {
            fila[fim++] = atual->dir;
        }

    }

    return raiz;
}

int main () {
    
    
    
    
    return 0;
}