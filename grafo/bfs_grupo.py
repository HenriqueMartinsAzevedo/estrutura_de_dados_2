from collections import deque

class grafo:
    def __init__(self):
        # A lista de adjacência é representada por um dicionário
        self.adjacencia = {}

    def inserir_vertice(self, vertice):
        # Cria o vértice apenas se ele ainda não existir
        if vertice not in self.adjacencia:
            self.adjacencia[vertice] = []
            return True
        return False

    def inserir_aresta(self, origem, destino):
        # Garante que os vértices existam (se não existirem, são criados)
        self.inserir_vertice(origem)
        self.inserir_vertice(destino)
        
        self.adjacencia[origem].append(destino)
        self.adjacencia[destino].append(origem)

    def remover_aresta(self, origem, destino):
        
        if origem in self.adjacencia and destino in self.adjacencia[origem]:
            self.adjacencia[origem].remove(destino)
            self.adjacencia[destino].remove(origem)
            return True
        return False

    def imprimir_grafo(self):
        if not self.adjacencia:
            print("O grafo está vazio.")
            return
        for vertice, vizinhos in self.adjacencia.items():

            print(f"Vértice [{vertice}] -> Vizinhos (Arestas): {vizinhos}")

    def busca_em_largura(self, inicio, alvo=None):
        if inicio not in self.adjacencia:
            print(f"Erro: O vértice '{inicio}' não existe no grafo.")
            return

        visitados = set()
        fila = deque([inicio])
        visitados.add(inicio)

        print(f"\n--- Iniciando BFS a partir de '{inicio}' ---")
        
        encontrado = False
        while fila:
            vertice_atual = fila.popleft()
            print(f"Visitando: {vertice_atual}")

            if alvo and vertice_atual == alvo:
                print(f">>> SUCESSO: Alvo '{alvo}' encontrado! <<<")
                encontrado = True
                break

            for vizinho in self.adjacencia[vertice_atual]:
                if vizinho not in visitados:
                    visitados.add(vizinho)
                    fila.append(vizinho)
        
        if alvo and not encontrado:
            print(f"--- O alvo '{alvo}' não foi encontrado no grafo. ---")


# ==========================================
# FUNÇÕES DO MENU
# ==========================================

meu_grafo = None

def criar():
    global meu_grafo
    if meu_grafo is None:
        meu_grafo = grafo()
        print("\n[!] Grafo criado com sucesso!")
    else:
        print("\n[!] Já existe um grafo ativo. Destrua-o primeiro.")

def buscar():
    if meu_grafo is None:
        print("\n[!] Crie o grafo primeiro (Opção 1).")
        return
    inicio = input("Digite o vértice de partida: ")
    alvo = input("Digite o vértice que deseja buscar (ou deixe vazio para varrer tudo): ")
    meu_grafo.busca_em_largura(inicio, alvo if alvo else None)

def inserir():
    if meu_grafo is None:
        print("\n[!] Crie o grafo primeiro (Opção 1).")
        return
    
    print("\nO que você deseja inserir?")
    print("1. Apenas um Vértice (isolado)")
    print("2. Uma Aresta (conexão entre dois vértices)")
    escolha = input("Sua escolha: ")

    if escolha == '1':
        vertice = input("Digite o nome do vértice: ")
        if meu_grafo.inserir_vertice(vertice):
            print(f"\n[!] Vértice '{vertice}' criado com sucesso!")
        else:
            print(f"\n[!] O vértice '{vertice}' já existe.")
            
    elif escolha == '2':
        origem = input("Digite o vértice de origem: ")
        destino = input("Digite o vértice de destino: ")
        meu_grafo.inserir_aresta(origem, destino)
        print(f"\n[!] Aresta entre '{origem}' e '{destino}' criada!")
        print("    (Se os vértices já estavam conectados, uma nova aresta paralela foi adicionada).")
    else:
        print("\n[!] Opção inválida.")

def remover():
    if meu_grafo is None:
        print("\n[!] Crie o grafo primeiro (Opção 1).")
        return
    origem = input("Digite o vértice de origem da aresta: ")
    destino = input("Digite o vértice de destino da aresta: ")
    
    if meu_grafo.remover_aresta(origem, destino):
        print("\n[!] Uma aresta foi removida com sucesso!")
    else:
        print("\n[!] Falha: Não existe aresta entre esses vértices.")

def imprimir():
    if meu_grafo is None:
        print("\n[!] Crie o grafo primeiro (Opção 1).")
        return
    print("\n--- Estrutura Atual do Grafo ---")
    meu_grafo.imprimir_grafo()
    print("-------------------------------------")

def destruir():
    global meu_grafo
    if meu_grafo is not None:
        meu_grafo = None
        print("\n[!] Grafo destruído. A memória foi liberada.")
    else:
        print("\n[!] Nenhum grafo para destruir.")

def menu():
    while True:
        print("\n" + "="*35)
        print("       MENU DO GRAFO")
        print("="*35)
        print("1. Criar grafo")
        print("2. Buscar (Busca em Largura)")
        print("3. Inserir (Vértice ou Aresta)")
        print("4. Remover aresta")
        print("5. Imprimir grafo")
        print("6. Destruir grafo")
        print("0. Sair")
        
        opcao = input("\nEscolha uma opção: ")
        
        if opcao == '1':
            criar()
        elif opcao == '2':
            buscar()
        elif opcao == '3':
            inserir()
        elif opcao == '4':
            remover()
        elif opcao == '5':
            imprimir()
        elif opcao == '6':
            destruir()
        elif opcao == '0':
            print("\nSaindo do sistema...")
            break
        else:
            print("\n[!] Opção inválida. Tente novamente.")

if __name__ == "__main__":
    menu()