#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Função para exportar o grafo original
void exportarGrafoDOT(const std::string& nomeArquivo, const std::vector<std::vector<int>>& grafo) {
    std::ofstream arquivo(nomeArquivo);
    
    // "graph" indica que o grafo é não-direcionado
    arquivo << "graph G {\n";
    arquivo << "    node [shape=circle, style=filled, fillcolor=lightblue];\n";

    // Para evitar duplicar arestas (ex: 0-1 e 1-0), usamos uma matriz de visitados ou a regra i < vizinho
    for (int i = 0; i < grafo.size(); ++i) {
        for (int vizinho : grafo[i]) {
            if (i < vizinho) { // Garante que a aresta só seja impressa uma vez
                arquivo << "    " << i << " -- " << vizinho << ";\n";
            }
        }
    }
    arquivo << "}\n";
    arquivo.close();
}

// Função para exportar a solução do Carteiro Chinês
// O vetor 'caminho_carteiro' contém a sequência de vértices visitados (ex: 0 -> 1 -> 2 -> 1 -> 0)
void exportarSolucaoCarteiro(const std::string& nomeArquivo, const std::vector<int>& caminho_carteiro) {
    std::ofstream arquivo(nomeArquivo);
    
    // Usamos digraph porque o carteiro percorre as ruas em um sentido específico no seu trajeto
    arquivo << "graph SolucaoCarteiro {\n";
    arquivo << "    node [shape=circle, style=filled, fillcolor=lightyellow, fontname=\"Arial\"];\n";

    // Para evitar poluir o gráfico se ele passar pela mesma rua na mesma direção, 
    // podemos colocar um contador ou apenas desenhar as setas sequenciais.
    for (size_t i = 0; i < caminho_carteiro.size() - 1; ++i) {
        int u = caminho_carteiro[i];
        int v = caminho_carteiro[i+1];
        
        // Coloca o número do passo na aresta (ex: 1º passo, 2º passo...)
        arquivo << "    " << u << " -> " << v << " [label=\" " << i+1 << "º \", penwidth=1.5];\n";
    }
    
    arquivo << "}\n";
    arquivo.close();
    std::cout << "Arquivo '" << nomeArquivo << "' gerado com sucesso para visualizacao!\n";
}

int main() {
    std::vector<std::vector<int>> grafo = {
        {1, 2},    // Vértice 0
        {0, 2, 3}, // Vértice 1
        {0, 1},    // Vértice 2
        {1, 4},    // Vértice 3
        {3}        // Vértice 4
    };

    exportarGrafoDOT("primeiro_grafo.dot", grafo);

    return 0;
}