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
// 10 - Raiz é o nó principal da árvore, a partir dele que fazemos a busca. A folha é o nó que não tem filhos. O nó interno é o nó que possui no mínimo um filho, porém não é a raiz e nem folha.
// 11 - O ancestral é nó que está acima de outro nó na árvore e os descendentes são os nós que está abaixo de outro nó na árvore.
// 12 - A profundidade é a quantidade de ligações no caminho da raiz até o nó que está sendo buscado.
// 13 - O grau de um nó é o número de filhos do nó. O grau de uma árvore é o máximo de grau dos nós.
// 14 - As árvores são estruturas de dados importantes devido ao fato de que, em certas situações, as buscas são mais rápidas do que em listas. A organização dos dados de forma hierárica também facilita buscas posteriores.
// 15 - 
//             10  
//      /       |     \
//     5       14      20
//    / \     /  \       \
//   3   7   12  16       27
//  /
// 1

// Folha: 1, 7, 12, 16, 27.
// Altura: Nível 3.
// Grau da árvore: 3.
#include <stdlib.h>
#include <stdio.h>
//16
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

    return novo;
}

int inserir(No *pai, No *filho){
    //17 - Inicializando uma árvore vazia.
    if(pai->prim_filho == NULL){
        pai->prim_filho = filho;
    }

    //18 - Inserindo um filho no nó.
    No *aux = pai->prim_filho; // A VAR aux é para não perder a referência do primeiro irmão.

    while(aux->prox_irmao != NULL){
        aux = aux->prox_irmao;
    }

    aux->prox_irmao = filho;

    return 1;
}
int main(){
    return 0;
}