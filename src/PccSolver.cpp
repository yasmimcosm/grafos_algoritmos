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