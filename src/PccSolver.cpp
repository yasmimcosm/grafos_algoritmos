#include "PccSolver.hpp"

#include <queue>
#include <functional>

namespace PccSolver {

    // Dijkstra
    std::vector<long long> dijkstra(
        int origem,
        const std::vector<std::vector<std::pair<int, int>>>& grafo
    ) {
        int n = grafo.size();

        std::vector<long long> dist(n, INF);
        dist[origem] = 0;

        std::priority_queue<
            std::pair<long long, int>,
            std::vector<std::pair<long long, int>>,
            std::greater<std::pair<long long, int>>
        > fila;

        fila.push({0, origem});

        while (!fila.empty()) {

            auto [distAtual, u] = fila.top();
            fila.pop();

            if (distAtual > dist[u])
                continue;

            for (auto [v, peso] : grafo[u]) {

                if (dist[u] + peso < dist[v]) {

                    dist[v] = dist[u] + peso;

                    fila.push({
                        dist[v],
                        v
                    });
                }
            }
        }

        return dist;
    }

    // 2.2 - Calcular distâncias mínimas entre os vértices ímpares
    std::vector<std::vector<long long>>
    calcularDistanciasMinimas(
        const Grafo& g,
        const std::vector<int>& impares
    ) {
        int n = impares.size();

        std::vector<std::vector<long long>>
            distancias(n, std::vector<long long>(n, INF));

        for (int i = 0; i < n; i++) {

            auto dist = dijkstra(
                impares[i],
                g.getListaAdjacencia()
            );

            for (int j = 0; j < n; j++) {
                distancias[i][j] = dist[impares[j]];
            }
        }

        return distancias;
    }

    // 2.3 - Emparelhamento (versão gulosa)
    std::vector<std::pair<int,int>>
    emparelhamentoMinimo(
        const std::vector<int>& impares,
        const std::vector<std::vector<long long>>& dist
    ) {
        int n = impares.size();

        std::vector<bool> usado(n, false);
        std::vector<std::pair<int,int>> pares;

        while (true) {

            int u = -1;

            for (int i = 0; i < n; i++) {
                if (!usado[i]) {
                    u = i;
                    break;
                }
            }

            if (u == -1)
                break;

            usado[u] = true;

            int melhorV = -1;
            long long melhorDist = INF;

            for (int v = 0; v < n; v++) {

                if (!usado[v] &&
                    dist[u][v] < melhorDist) {

                    melhorDist = dist[u][v];
                    melhorV = v;
                }
            }

            usado[melhorV] = true;

            pares.push_back({
                impares[u],
                impares[melhorV]
            });
        }

        return pares;
    }

}