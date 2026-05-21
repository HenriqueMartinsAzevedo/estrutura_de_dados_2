#include <stdio.h>
#include <stdlib.h>

// ============================
// ESTRUTURA DO NÓ
// ============================
typedef struct No {
    int valor;
    struct No *prox;
} No;

// ponteiro para o início da lista
No *head = NULL;

// ============================
// INSERIR (no início)
// ============================
void inserir() {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        return;
    }

    printf("Digite o valor: ");
    scanf("%d", &novo->valor);
    
    
    novo->prox = head;
    head = novo;

    printf("Elemento inserido!\n");
}

// ============================
// INSERIR (no fim)
// ============================

void inserir_fim() {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        return;
    }

    printf("Digite o valor: ");
    scanf("%d", &novo->valor);
    No *ultimo = head;
    
    while(ultimo->prox != NULL){
        ultimo = ultimo->prox;
    }
    ultimo->prox = novo;
    novo->prox = NULL;
    
    printf("Elemento inserido!\n");
}

// ============================
// Inserir (Meio)
// ============================

void inserir_meio() {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de Alocacao\n");
        return;
    }

    printf("Digite o valor: ");
    scanf("%d", &novo->valor);

    if (head == NULL) {
        novo->prox = NULL;
        head = novo;
        return;
    }

    No *lento = head;
    No *rapido = head;
    No *anterior = NULL;

    while (rapido != NULL && rapido->prox != NULL) {
        anterior = lento;
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    if (anterior == NULL) {
        novo->prox = head->prox;
        head->prox = novo;
    } 
    else {
        novo->prox = lento;
        anterior->prox = novo;
    }
}
// ============================
// REMOVER (por valor)
// ============================
void remover() {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    int valor;
    printf("Digite o valor a remover: ");
    scanf("%d", &valor);

    No *atual = head;
    No *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento nao encontrado!\n");
        return;
    }

    // remove o primeiro
    if (anterior == NULL) {
        head = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);

    printf("Elemento removido!\n");
}

// ============================
// BUSCAR
// ============================
void buscar() {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    int valor, pos = 0;
    printf("Digite o valor a buscar: ");
    scanf("%d", &valor);

    No *atual = head;

    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("Encontrado na posicao %d\n", pos);
            return;
        }
        atual = atual->prox;
        pos++;
    }

    printf("Nao encontrado!\n");
}

// ============================
// EXIBIR
// ============================
void exibir() {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No *atual = head;

    printf("\nLista:\n");

    while (atual != NULL) {
        printf("[Valor: %d | Endereco: %p | Prox: %p] -> ",
               atual->valor, atual, atual->prox);
        atual = atual->prox;
    }

    printf("NULL\n");
    return;
}

// ============================
// MENU
// ============================
void menu() {
    printf("\n===== LISTA ENCADEADA =====\n");
    printf("1 - Inserir Início\n");
    printf("2 - Inserir no Fim\n");
    printf("3 - Inserir no Meio\n");
    printf("4 - Remover Elemento\n");
    printf("5 - Buscar Elemento\n");
    printf("6 - Exibir Lista\n");
    printf("7 - Sair\n");
    printf("Opcao: ");
}

// ============================
// MAIN
// ============================
int main() {
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1) inserir();
        else if (opcao == 2) inserir_fim();
        else if(opcao == 3) inserir_meio();
        else if (opcao == 4) remover();
        else if (opcao == 5) buscar();
        else if (opcao == 6) exibir();
        else if (opcao == 7) printf("Encerrando...\n");
        else printf("Opcao invalida!\n");

    } while (opcao != 7);

    return 0;
}