#ifndef PCCSOLVER_HPP
#define PCCSOLVER_HPP
#include <vector>
using namespace std;
#include <utility>
#include "Grafo.hpp"
using namespace std;

namespace PccSolver {

    const long long INF = 1e18;

    vector<long long> dijkstra(
        int origem,
        const vector<vector<pair<int, int>>>& grafo,
        vector<int>& pai
    );

    vector<vector<long long>>
    calcularDistanciasMinimas(
        const Grafo& g,
        const vector<int>& impares
    );

    vector<pair<int,int>>
    emparelhamentoMinimo(
        const vector<int>& impares,
        const vector<vector<long long>>& dist
    );

    vector<int> reconstruirCaminho(
        int origem,
        int destino,
        const vector<int>& pai
    );

    int obterPesoAresta(
        const Grafo& g,
        int u,
        int v
    );

    void duplicarArestas(
        Grafo& g,
        const vector<int>& caminho
    );

    vector<int> circuitoEuleriano(
        const Grafo& g,
        int inicio
    );

}

#endif