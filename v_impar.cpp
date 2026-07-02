#include <iostream>
#include <vector>

// Função que identifica e retorna os vértices de grau ímpar
std::vector<int> identificaVerticesImpares(const std::vector<std::vector<int>>& grafo) {
    std::vector<int> vertices_impares;

    // Varia de 0 até o total de vértices
    for (int i = 0; i < grafo.size(); ++i) {
        // O grau do vértice 'i' é o número de vizinhos que ele possui
        int grau = grafo[i].size();

        // Se o resto da divisão por 2 for diferente de 0, o grau é ímpar
        if (grau % 2 != 0) {
            vertices_impares.push_back(i); // Adiciona o vértice ao conjunto
        }
    }

    return vertices_impares;
}

int main() {
    // Exemplo de Grafo com 5 vértices (0 a 4) representado por Lista de Adjacência
    // Vértice 0 conectado a 1 e 2 (Grau 2 - Par)
    // Vértice 1 conectado a 0, 2 e 3 (Grau 3 - Ímpar)
    // Vértice 2 conectado a 0 e 1 (Grau 2 - Par)
    // Vértice 3 conectado a 1 e 4 (Grau 2 - Par)
    // Vértice 4 conectado a 3 (Grau 1 - Ímpar)
    std::vector<std::vector<int>> grafo = {
        {1, 2},    // Vértice 0
        {0, 2, 3}, // Vértice 1
        {0, 1},    // Vértice 2
        {1, 4},    // Vértice 3
        {3}        // Vértice 4
    };

    // Chamada da funcao
    std::vector<int> impares = identificarVerticesImpares(grafo);

    // Exibindo o conjunto de vértices ímpares
    std::cout << "Vertices de grau impar: { ";
    for (int v : impares) {
        std::cout << v << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}