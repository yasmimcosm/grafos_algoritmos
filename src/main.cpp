#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Grafo.hpp"
#include "GeradorGrafo.hpp"
#include "PccSolver.hpp"
#include "PlotGrafos.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // VALORES PADRÃO (caso você rode na mão sem passar parâmetros)
    int vertices = 10;
    int arestas = 15;

    // SE O SCRIPT PYTHON PASSAR ARGUMENTOS, ELES ENTRAM AQUI:
    if (argc >= 3) {
        vertices = std::atoi(argv[1]);
        arestas = std::atoi(argv[2]);
    }

    Grafo g = GeradorGrafo::gerarGrafo(vertices, arestas, 1, 17);

    vector<int> impares = g.getVerticesImpares();

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
    for (auto par : pares) {

        int origem = par.first;
        int destino = par.second;

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

    vector<int> imparesRestantes = g.getVerticesImpares();

    cout << "\nVertices impares apos a duplicacao: { ";

    for (int v : imparesRestantes)
        cout << v << " ";

    cout << "}" << endl;
    cout << "\nArestas duplicadas com sucesso!" << endl;

    // 2.5 - Circuito Euleriano

    int inicio = 0;

    for (int i = 0; i < g.getNumVertices(); i++) {
        if (g.getGrau(i) > 0) {
            inicio = i;
            break;
        }
    }

    vector<int> circuito =
        PccSolver::circuitoEuleriano(g, inicio);

    cout << "\nCircuito Euleriano encontrado:\n";

    for (int v : circuito)
        cout << v << " ";

    cout << endl;

    return 0;
}

