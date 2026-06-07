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

int main(){
    return 0;
}