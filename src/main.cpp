#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Grafo.hpp"
#include "GeradorGrafo.hpp"
#include "PccSolver.hpp"

using namespace std;

int main() {
    srand(time(NULL));

    Grafo g = GeradorGrafo::gerarGrafo(9, 27, 1, 50);

    cout << "Grafo aleatorio gerado com sucesso!" << endl;

    // 2.1 - Encontrar vertices impares
    vector<int> impares = g.getVerticesImpares();

    cout << "\nVertices impares detectados: { ";
    for(int v : impares)
        cout << v << " ";
    cout << "}" << endl;

    // 2.2 - Calcular distancias minimas
    auto dist = PccSolver::calcularDistanciasMinimas(
        g,
        impares
    );

    cout << "\nMatriz de distancias minimas entre vertices impares:\n";

    for(size_t i = 0; i < dist.size(); i++) {
        for(size_t j = 0; j < dist[i].size(); j++) {
            cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    // 2.3 - Emparelhamento minimo
    auto pares = PccSolver::emparelhamentoMinimo(
        impares,
        dist
    );

    cout << "\nEmparelhamento encontrado:\n";

    long long custoTotal = 0;

    for(auto p : pares) {

        cout << p.first
             << " <-> "
             << p.second
             << endl;

        int i = -1;
        int j = -1;

        for(size_t k = 0; k < impares.size(); k++) {
            if(impares[k] == p.first) i = k;
            if(impares[k] == p.second) j = k;
        }

        if(i != -1 && j != -1)
            custoTotal += dist[i][j];
    }

    cout << "\nCusto total do emparelhamento: "
         << custoTotal
         << endl;
    
    // 2.4 - Duplicação das arestas
    for (auto [origem, destino] : pares) {

        vector<int> pai;

        PccSolver::dijkstra(
            origem,
            g.getListaAdjacencia(),
            pai
        );

        vector<int> caminho =
            PccSolver::reconstruirCaminho(
                origem,
                destino,
                pai
            );

        PccSolver::duplicarArestas(
            g,
            caminho
        );
    }

    cout << "\nArestas duplicadas com sucesso!" << endl;

    // 2.5 - Circuito Euleriano

    vector<int> circuito =
        PccSolver::circuitoEuleriano(g, 0);

    cout << "\nCircuito Euleriano encontrado:\n";

    for (int v : circuito)
        cout << v << " ";

    cout << endl;

    return 0;
}