#include <stdlib.h>
#include <stdio.h>
// Implemente uma ABB sem utilizar recursão.

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor){
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No* inserir(No *raiz, int valor){

    No *novo = criarNo(valor);

    if(raiz == NULL)
        return novo;

    No *atual = raiz;
    No *pai = NULL;

    while(atual != NULL){

        pai = atual;

        if(valor < atual->valor)
            atual = atual->esq;

        else if(valor > atual->valor)
            atual = atual->dir;

        else{
            free(novo); // evita duplicatas
            return raiz;
        }
    }

    if(valor < pai->valor)
        pai->esq = novo;
    else
        pai->dir = novo;

    return raiz;
}

No* buscar(No *raiz, int valor){

    No *atual = raiz;

    while(atual != NULL){

        if(valor == atual->valor)
            return atual;

        if(valor < atual->valor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    return NULL;
}

// 21 - Implemente uma árvore binária utilizando alocação dinâmica.
No* inserirDinamico(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    
    if (valor < raiz->valor) {
        raiz->esq = inserirDinamico(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserirDinamico(raiz->dir, valor);
    }
    
    return raiz;
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}
//22 - Crie uma função que transforme uma árvore binária em espelho.
void espelho(No *raiz){
    if(raiz == NULL)
        return;

    No *temp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = temp;

    espelho(raiz->esq);
    espelho(raiz->dir);
}

int altura(No *raiz){
    if(raiz == NULL)
        return -1;

    int altEsq = altura(raiz->esq);
    int altDir = altura(raiz->dir);

    return (altEsq > altDir ? altEsq : altDir) + 1;
}
int balanceada(No *raiz){
    if(raiz == NULL)
        return 1;

    int altEsq = altura(raiz->esq);
    int altDir = altura(raiz->dir);

    if(abs(altEsq - altDir) > 1)
        return 0;

    return balanceada(raiz->esq) &&
           balanceada(raiz->dir);
}
int main() {
    No* raiz = NULL;
    
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 12);
    
    emOrdem(raiz);
    printf("\n");
    
    
    printf("Antes:\n");
    emOrdem(raiz);

    espelho(raiz);

    printf("\nDepois:\n");
    emOrdem(raiz);

    if(balanceada(raiz)){
    printf("A arvore esta balanceada.\n");}
    else{
    printf("A arvore nao esta balanceada.\n");}

    liberarArvore(raiz);
    return 0;
}