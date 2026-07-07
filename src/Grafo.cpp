#include "Grafo.hpp"
#include <iostream>
using namespace std;
// Construtor 
Grafo::Grafo(int vertices) {
    this->numVertices = vertices;
    this->listaAdjacencia.resize(vertices);
}


// Adiciona uma aresta entre cada par de vértices selecionados 
void Grafo::adicionarAresta(int u, int v, int peso) {
    listaAdjacencia[u].push_back({v, peso});
    listaAdjacencia[v].push_back({u, peso});
}

// Retorna o número de vértices
int Grafo::getNumVertices() const{
    return this->numVertices;
}

// Retorna o a lista adjacência (grafo)
const vector<vector<pair<int, int>>>& Grafo::getListaAdjacencia() const {
    return listaAdjacencia;
}

// Retorna o grau de um vérice específico
int Grafo::getGrau(int vertice) const{
    return listaAdjacencia[vertice].size();
}

// retorna uma lista com todos os graus impares
const vector<int> Grafo::getVerticesImpares() const {
    vector<int> impares;
    int numVertices = getNumVertices();

    for (int i = 0; i < numVertices; ++i) {
        // Se o grau do vértice 'i' for ímpar
        if (getGrau(i) % 2 != 0) {
            impares.push_back(i); // Separa ele no conjunto
        }
    }

    return impares;
}

// imprimi e o grafo em terminal para vizualização rápida.
void Grafo::imprimir() const {
    int numVertices = getNumVertices();

    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertice " << i << " conecta com:\n";
        for (auto& aresta : listaAdjacencia[i]) {
            int vizinho = aresta.first;
            int peso = aresta.second;
            cout << "  -> " << vizinho << " (peso: " << peso << ")\n";
        }
    }
}