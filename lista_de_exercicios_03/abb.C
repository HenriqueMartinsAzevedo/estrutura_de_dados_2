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
