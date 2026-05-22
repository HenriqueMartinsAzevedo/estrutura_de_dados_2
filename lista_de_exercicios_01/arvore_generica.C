// Resposta das Questões conceituais.
// 1 - C
// 2 - B
// 3 - C
// 4 - C
// 5 - B
// 6 - A
// 7 - D
// 8 - A
// 9 - As árvores são estruturas de dados hierárquicas, seguindo a seguinte ordem: a raiz é o nó principal, seguida dos filhos, e os nós que não têm filhos são as folhas. A árvore mais utilizada é a binária, pois reduz o tempo de busca, já que na árvore binária o nó tem no máximo 2 filhos.
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

No* CriarNO(int valor){
    No* novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prim_filho = NULL;
    novo->prox_irmao = NULL;


}
int main(){
    return 0;
}