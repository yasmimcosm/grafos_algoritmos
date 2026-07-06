#ifndef PCCSOLVER_HPP
#define PCCSOLVER_HPP

#include <vector>
using namespace std;

namespace PccSolver {
    const long long INF = 1e18;

    vector<long long> dijkstra(int origem, const vector<vector<pair<int, int>>>& grafo);

}

#endif