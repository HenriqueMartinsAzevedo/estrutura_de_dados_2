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

//24 - A recursão é muito utilizada em árvores devido ao fato de que elas possuem subárvores com a mesma estrutura da árvore formada por nós pai e filhos. Isso permite que o algoritmo seja reutilizado em diferentes partes da árvore.

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

int inserir(No *raiz, No *filho){
    //17 - Inicializando uma árvore vazia.
    if(raiz->prim_filho == NULL){
        raiz->prim_filho = filho;
        return 1;
    }

    //18 - Inserindo um filho no nó.
    No *aux = raiz->prim_filho; // A VAR aux é para não perder a referência do primeiro irmão.

    while(aux->prox_irmao != NULL){
        aux = aux->prox_irmao;
    }

    aux->prox_irmao = filho;

    return 1;
}
 
void imprimir(No *raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d ", raiz->valor);

    imprimir(raiz->prim_filho);
    imprimir(raiz->prox_irmao);
}
//19 - Função para contar os Nós
int contarNo(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    return 1 + contarNo(raiz->prim_filho) + contarNo(raiz->prox_irmao);
}
//20 - Função recursiva para calcular a altura da árvore
int alturaDaArvore(No *raiz){
    if(raiz == NULL){
        return -1;
    }

    //A cada recursão vai somando 1 no contador conforme for descendo na árvore.
    int alturaFilho = 1 + alturaDaArvore(raiz->prim_filho);
    
    //Navegando entre os irmãos do nó filho
    int alturaIrmao = alturaDaArvore(raiz->prox_irmao);

    if(alturaFilho > alturaIrmao){return alturaFilho;
    }
    else{return alturaIrmao;
    }
}

//21 - Função para contar as quantidades de folha na árvore
int contarFolhas(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    // Se encontrar uma folha soma + 1 no contador
    if(raiz->prim_filho == NULL){
        return 1 + contarFolhas(raiz->prox_irmao);
    }
    //Se o nó não for folha, continue buscando a folha.
    return contarFolhas(raiz->prim_filho) + contarFolhas(raiz->prox_irmao);
}

//22 - Função para verificar se existe um valor na árvore
int verificarValor(No *raiz){
    if(raiz != NULL){
        printf("%d\n", raiz->valor);
        verificarValor(raiz->prim_filho);
        verificarValor(raiz->prox_irmao);
        return 1;
    }
    return 0;
}
//23 - Função para imprimir os nós por nível.
int maior(int a, int b){
    if (a > b) return a;
    else return b;
}

void imprimirNivel(No *raiz, int nivel){
    if(raiz == NULL)
        return;

    if(nivel == 0){
        printf("%d ", raiz->valor);
        return;
    }

    No *filho = raiz->prim_filho;

    while(filho != NULL){
        imprimirNivel(filho, nivel - 1);
        filho = filho->prox_irmao;
    }
}

void imprimirPorNivel(No *raiz){
    int h = alturaDaArvore(raiz);

    for(int i = 0; i <= h; i++){
        imprimirNivel(raiz, i);
        printf("\n");
    }
}
//25 - Implemente uma função para destruir/liberar toda a árvore
void liberarArvore(No *raiz){
    if(raiz == NULL){
        return;
    }

    liberarArvore(raiz->prim_filho);
    liberarArvore(raiz->prox_irmao);
    free(raiz);
}
int main(){

    No *A = CriarNO(10); 
    No *B = CriarNO(20);
    No *C = CriarNO(30);
    No *D = CriarNO(40);
    No *E = CriarNO(50);
    No *F = CriarNO(60);
    No *G = CriarNO(70);

    inserir(A, B);
    inserir(A, C);
    inserir(A, D);
    inserir(D, E);
    inserir(C, F);
    inserir(B, G);

    printf("Elementos da árvore:\n");
    imprimir(A);

    printf("\n\nQuantidade de nós: %d\n", contarNo(A));

    printf("\nAltura da arvore: %d\n", alturaDaArvore(A));

    printf("\nQuantidade de Folhas: %d\n", contarFolhas(A));

    printf("\n");

    if(verificarValor(A) == 1){
        printf("\nHá valores na árvore.\n");
    }
    else printf("Não há valores na árvore\n");
        
    imprimirPorNivel(A);
    return 0;
}