#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <utility> // Para usar pair
using namespace std;

class Grafo {
private:
    int numVertices;
    
    // Lista de adjacência: uma lista que guarda várias listas
    // cada lista dentro da lista principal representa um vértices e seus elementos são seus vértices vizinhos
    vector<vector<pair<int, int>>> listaAdjacencia;

public:
    // Construtor
    Grafo(int numVertices);

    // Adiciona uma aresta entre o vértice 'u' e 'v' com um determinado 'peso'
    void adicionarAresta(int u, int v, int peso);

    // Retorna o número de vértices do grafo
    int getNumVertices() const;

    // Retorna o grau (número de conexões) de um vértice específico
    int getGrau(int vertice) const;

    // Retorna uma lista com os vértices adjacentes
    const vector<pair<int, int>> getVerticesImpares() const;

    // retorna a listaAdjacência mais atual
    const vector<vector<pair<int, int>>>& getListaAdjacencia() const;

    void imprimir() const;
};

#endif // GRAFO_HPP