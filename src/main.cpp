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

    vector<int> impares = g.getVerticesImpares();

    cout << "Vertices impares detectados no grafo aleatorio: { ";
    for(int v : impares) cout << v << " ";
    cout << "}" << endl;
}