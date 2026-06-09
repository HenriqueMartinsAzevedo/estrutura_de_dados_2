//1 - B
//2 - C
//3 - D
//4 - C
//5 - C
//6 - B
//7 - Na árvore cheia não pode ter nó com apenas um filho, os níveis não precisam estar totalmente preenchido e todo nó interno possui dois filhos, já a árvore completa pode possuir nós com apenas 1 filho, os níveis podem estar totalmente preenchido exceto o último e não é necessário que todos os nós possuam 2 filhos.
//8 - Na pré-ordem primeiro percorre o pai, em seguida o filho da esquerda e depois o filho da direita. Em ordem a visita começa pelo filho da esquerda, em seguida o pai e por fim o filho da direita. Pós-ordem começa pelo filho da esquerda, em seguida pelo filho da direita e por fim o pai.

#include <stdio.h>
#include <stdlib.h>

//36 - implemente a estrutura de um nó de árvore binária.
typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
}No;
//37 - Crie uma função para inserir os nós manualmente em uma árvore binária.
No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo; 
}
No* inserir(No *raiz, int valor, int lado){

    if(raiz == NULL)
        return criarNo(valor);

    //Se o lado for 1, insira a esquerda
    if(lado == 1){
        if(raiz->esq == NULL)
            raiz->esq = criarNo(valor);
    }
    //Se o lado for 2, insira a direita
    else if(lado == 2){
        if(raiz->dir == NULL)
            raiz->dir = criarNo(valor);
    }

    return raiz;
}
void imprimir(No *raiz){
    if(raiz == NULL) return ;
    
    printf("%d ", raiz->valor);
    imprimir(raiz->esq);
    imprimir(raiz->dir);
    
}
//38 - Implemente o percurso em pré-ordem
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}
//39 - Implemente o percurso em ordem
void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}
//40 - Implemente o percurso pós-ordem
void posOrdem(No *raiz){
    if(raiz!=NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d", raiz->valor);
    }
}
//41 - Crie uma função para contar os número de nós da árvore binária.
int contarNos(No *raiz){
    if(raiz == NULL){
        return 0;
    }

    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}
//42 - Implemente uma função que calcule a altura da árvore binária
int calcularAltura(No* raiz){
    if(raiz == NULL){
        return -1;
    }

    //A cada recursão vai somando 1 no contador conforme for descendo na árvore, até encontrar a folha.
    int alturaEsq = 1 + calcularAltura(raiz->esq);
    int alturaDir = calcularAltura(raiz->dir);

    if(alturaEsq > alturaDir){return alturaEsq + 1;
    }
    else{return alturaDir + 1;
    }
}
//43 - Implemente uma função que conte quantos nós folhas existem
int contarFolhas(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    // Se encontrar uma folha soma + 1 no contador
    if(raiz->esq == NULL && raiz->dir == NULL){
        return 1;
    }
    //Se o nó não for folha, continue buscando a folha.
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}
//44 - Crie uma função que espelhe uma árvore binária.
void espelharArvore(No* raiz){
    if(raiz == NULL) return;


    //Para descer até a folha da esquerda como direita
    espelharArvore(raiz->esq);
    espelharArvore(raiz->dir);

    //utiliza-se o Nó temp para não perder a referência durante o espelhamento.
    No* temp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = temp;

}
int main(){

    No *raiz = criarNo(10);

    inserir(raiz, 5, 1);          //inserir a esquerda de 10
    inserir(raiz, 20, 2);         //inserir a direita de 10

    inserir(raiz->esq, 3, 1);     //inserir a esquerda de 5
    inserir(raiz->esq, 8, 2);     //inserir a direita de 5

    imprimir(raiz);

    emOrdem(raiz);
    preOrdem(raiz);
    posOrdem(raiz);

    pritf("%d", contarNos(raiz));
    return 0;
}
