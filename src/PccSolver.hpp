#ifndef PCCSOLVER_HPP
#define PCCSOLVER_HPP

#include <vector>

namespace PccSolver {
    const long long INF = 1e18;

    std::vector<long long> dijkstra(int origem, const std::vector<std::vector<std::pair<int, int>>>& grafo);

}

#endif