#ifndef PCCSOLVER_HPP
#define PCCSOLVER_HPP

#include <vector>
using namespace std;
#include <utility>

#include "Grafo.hpp"

namespace PccSolver {

    const long long INF = 1e18;

    std::vector<long long> dijkstra(
        int origem,
        const std::vector<std::vector<std::pair<int, int>>>& grafo
    );

    std::vector<std::vector<long long>>
    calcularDistanciasMinimas(
        const Grafo& g,
        const std::vector<int>& impares
    );

    std::vector<std::pair<int,int>>
    emparelhamentoMinimo(
        const std::vector<int>& impares,
        const std::vector<std::vector<long long>>& dist
    );

}

#endif