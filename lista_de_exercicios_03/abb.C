// Respostas:
// 1 - C
// 2 - C
// 3 - B
// 4 - B
// 5 - O primeiro valor inserido na árvore é a raiz. Já com os valores inseridos posteriores, é verificado se são maiores ou menores que o nó atual, começando pela raiz: se for menor, segue para a esquerda, se for maior, segue para a direita. Isso se repete até encontrar um espaço vazio, onde o valor será finalmente inserido.
// 6 - A busca começa pela raiz. Se o valor buscado for igual ao nó atual, ele é retornado. Se for menor, ele vai ser procurado descendo pelas subárvores da esquerda, se for maior, vai ser procurado descendo pelas subárvores da direita. Esse processo se repete até encontrar o valor e, caso o valor não for encontrado retorna NULL.
// 7 - Remoção da folha: Neste caso é necessário apenas remover o nó.
// 7 - Remoção de nó com um filho: Neste caso, o filho é colocado no lugar no pai (Nó a ser removido), depois que é feito a ligação, o nó é removido.
//7 - Remoção do nó com dois filhos: Já neste caso, podemos seguir a regra do sucessor que o nó a ser removido, vai ser substituído pelo nó de menor valor da subárvore da direita, ou podemos seguir a regra do predecessor que é o nó de maior valor da subárvore da esquerda.
//8 - A principal vantagem é que a ABB possui regra de ordenação as dos valores menores que a raíz ficam a esquerda e valores maiores que a raíz ficada na direiita, consequentemente o processo de busca mais rápido.
//9 - O problema do desbalanceamento em ABB é que o tempo de busca será maior, por exemplo se o valor procurado for uma folha de 1000 nós a complexidade cai para O(n), já na ABB balanceada a complexidade é de O(log n) que é mais rápido.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//10 -  Implemente a função de inserção em uma ABB usando recursão.
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

No* inserir(No* raiz, int valor){
    if(raiz == NULL) return criarNo(valor);

    if(valor < raiz->valor){
        raiz->esq  = inserir(raiz->esq, valor);
    } 

    if(valor > raiz->valor){
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}
//11 - Implemente a função de busca em uma ABB.
No* buscar(No* raiz, int valor){
    if(raiz == NULL || raiz->valor == valor) return raiz;

    //Caso  valor for menor que a raiz, retorna o nó esquerda.
    if(valor < raiz->valor){
        return buscar(raiz->esq, valor);
    }

    //caso valor for maior que a raiz, retorna o nó da direita
    return buscar(raiz->dir, valor);
}
//12 - Implemente o percurso em ordem em uma ABB.
void emOrdem(No* raiz){
    emOrdem(raiz->esq);
    printf("%d", raiz->valor);
    emOrdem(raiz->dir);
}
//13 - Implemente a remoção de um nó folha em uma ABB.
No* removerFolha(No* raiz, int valor){
   if(raiz == NULL) return NULL;

   //se o valor procurado for menor que raiz, ele vai ser procurado na subárvore a esquerda
   if(valor < raiz->valor){
    raiz->esq = removerFolha(raiz->esq, valor);
   }

    //se o valor procurado for maior que raiz, ele vai ser procurado na subárvore a direita
   else if(valor > raiz->valor){
    raiz->dir = removerFolha(raiz->dir, valor);
   }

   //Quando o valor for encontrado é verificado se é uma folha
   else{
    if(raiz->esq == NULL && raiz->dir == NULL){
        free(raiz); //Libera a memória alocada para o nó
        return NULL;
    }
    else{
        //Caso não seja uma folha retorna apenas a raiz.
        return raiz;
    }
   }
   return raiz;
}
//14 - Implemente a remoção de um nó com apenas um filho.
No* removerUmFilho(No* raiz, int valor){
    if(raiz == NULL) return NULL;

    //se o valor procurado for menor que raiz, ele vai ser procurado na subárvore a esquerda
   if(valor < raiz->valor){
    raiz->esq = removerUmFilho(raiz->esq, valor);
   }

    //se o valor procurado for maior que raiz, ele vai ser procurado na subárvore a direita
   else if(valor > raiz->valor){
    raiz->dir = removerUmFilho(raiz->dir, valor);
   }

   //Se o nó for encontrado
   else{
    //caso o nó possua filha só a direita.
    if(raiz->esq == NULL){
        No* temp = raiz->dir; //Para não perder a referência do nó filho que irá substituir o pai.
        free(raiz); //Libera memória do nó a ser removido
        return temp; //retorna o filho para conectar ao espaço vazio do nó removido.
    }
    //caso o nó possua apenas filho a esquerda
    else if(raiz->dir == NULL){
        No* temp = raiz->esq; //Para não perder a referência do nó filho que irá substituir o pai. 
        free(raiz); //Libera memória do nó a ser removido
        return temp; //retorna o filho para conectar ao espaço vazio do nó removido. 
    }
   }
   return raiz;
}
//15 - Implemente a remoção de um nó com dois filhos utilizando sucessor em ordem.
//Função auxiliar para encontrar valor minímo da direita.
No* encontrarMinimo(No* atual){

    while(atual != NULL && atual->esq != NULL){
        atual = atual->esq;
    }
    return atual;
}

No* removerDoisFilhos(No* raiz, int valor){
    if (raiz == NULL) return NULL;

    //Buscando nó, verificando se está a esquerda ou na direita.
    if(valor < raiz->valor){
        raiz->esq = removerDoisFilhos(raiz->esq, valor);
    }
    else if(valor > raiz->valor){
        raiz->dir = removerDoisFilhos(raiz->dir, valor);
    }
    else{
        if (raiz->esq != NULL && raiz->dir != NULL){
        //Passando o nó a direita da chave de busca
        No* temp = encontrarMinimo(raiz->dir);

        //a raiz recebe o menor valor da subárvore da direita.
        raiz->valor = temp->valor;
    
        //Agora a função deleta o nó menor da subárvore que está duplicado.
        raiz->dir = removerUmFilho(raiz->dir, temp->valor);
    }
    }
    return raiz;
}
//Função auxiliar para o int main.
No* remover(No* raiz, int valor){
    No* no = buscar(raiz, valor);

    if(no == NULL)
        return raiz;

    if(no->esq == NULL && no->dir == NULL)
        return removerFolha(raiz, valor);

    if(no->esq == NULL || no->dir == NULL)
        return removerUmFilho(raiz, valor);

    return removerDoisFilhos(raiz, valor);
}

//16 -  Implemente uma função que encontre: Maior valor e menor valor
No* menorValor(No* raiz){
    //caso a árvore esteja vazia.
    if(raiz == NULL) return NULL;

    //caso chegue em uma folha na subárvore a esquerda.
    if(raiz->esq == NULL) return raiz;

    //Continua descendo para os nós a esquerda.
    return menorValor(raiz->esq);
}

No* maiorValor(No* raiz){
    //caso a árvore esteja vazia.
    if(raiz == NULL) return NULL;

    //caso chegue em uma folha na subárvore a direita.
    if(raiz->dir == NULL) return raiz;

    //Continua descendo para os nós a direita.
    return maiorValor(raiz->dir);
}
// 17 -  Crie uma função que verifique se uma árvore é realmente uma ABB válida.
int BSTvalida(No* raiz, int min, int max){
    if(raiz == NULL) return 1;

    if(raiz->valor <=min || raiz->valor >= max) return 0;
    return BSTvalida(raiz->esq, min, raiz->valor) && BSTvalida(raiz->dir, raiz->valor, max);
}
//18 -  Implemente uma função que conte quantos níveis existem na ABB.
int contarNiveis(No* raiz){
    if(raiz == NULL) return 0;

    int niveisEsq = contarNiveis(raiz->esq);
    int niveisDir = contarNiveis(raiz->dir);

    if(niveisEsq > niveisDir) return niveisEsq + 1;
    else return niveisDir + 1;
}
// 19 - Crie um menu completo de ABB contendo 
int main(){
    No* raiz = NULL;

    int opcao;
    int valor;

    do{
        printf("\n===== MENU ABB =====\n");
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir em ordem\n");
        printf("5 - Mostrar altura\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("Valor para inserir: ");
                scanf("%d", &valor);

                raiz = inserir(raiz, valor);
                break;

            case 2:
                printf("Valor para buscar: ");
                scanf("%d", &valor);

                if(buscar(raiz, valor))
                    printf("Valor encontrado!\n");
                else
                    printf("Valor nao encontrado!\n");

                break;

            case 3:
                printf("Valor para remover: ");
                scanf("%d", &valor);

                raiz = remover(raiz, valor);
                printf("Remocao concluida.\n");

                break;

            case 4:
                printf("ABB em ordem: ");
                emOrdem(raiz);
                printf("\n");
                break;

            case 5:
                printf("Altura da ABB: %d\n", contarNiveis(raiz) - 1);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}