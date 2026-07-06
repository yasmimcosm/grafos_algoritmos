#include "GeradorGrafo.hpp"
#include "Grafo.hpp"
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

namespace GeradorGrafo{
    Grafo gerarGrafo(int numVertices, int numArestas, int pesoMin, int pesoMax) {
        Grafo g(numVertices);

        // garante que o grafo é conectado
        for (int i = 1; i < numVertices; ++i) {
            int peso = pesoMin + (rand() % (pesoMax - pesoMin + 1));
            g.adicionarAresta(i - 1, i, peso);
        }

        // adiciona mais arestas
        int arestas = numArestas - (numVertices - 1);
        while (arestas > 0) {
            int u = rand() % numVertices;
            int v = rand() % numVertices;

            // if loop, continue
            if (u == v) continue;

            int peso = pesoMin + (rand() % (pesoMax - pesoMin + 1));
            g.adicionarAresta(u, v, peso);
            arestas--;
        }

        return g;
    }

}
