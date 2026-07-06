#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grafo.hpp"
#include "GeradorGrafo.hpp"
#include "PccSolver.hpp"
#include "PlotGrafos.hpp"

using namespace std;

int main() {
    srand(time(NULL));

    Grafo g = GeradorGrafo::gerarGrafo(50,100, 1, 50);

    cout << "Grafo aleatorio gerado com sucesso!" << endl;

    vector<pair<int, int>> impares = g.getVerticesImpares();

    cout << "Vertices impares detectados no grafo aleatorio: { " << endl;
    for(auto v : impares) cout << "(" <<v.first << ", " << v.second << ")" << endl;
    cout << "}" << endl;
    
    vector<vector<pair<int, int>>> listaAdjacencia = g.getListaAdjacencia();
    PlotGrafos::exportarGrafoDOT("grafo_original.dot", listaAdjacencia);
}
