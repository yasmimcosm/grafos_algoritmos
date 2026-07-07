#include "PccSolver.hpp"

#include <queue>
#include <functional>
#include <stack>
#include <algorithm>
using namespace std;

namespace PccSolver {

    // Dijkstra
    std::vector<long long> dijkstra(
        int origem,
        const vector<vector<pair<int, int>>>& grafo,
        vector<int>& pai// será preenchido durante a execução
    ) {
        int n = grafo.size();

        std::vector<long long> dist(n, INF);
        dist[origem] = 0;

        pai.assign(n,-1);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > fila;

        fila.push({0, origem});

        while (!fila.empty()) {

            pair<long long, int> atual = fila.top();
            long long distAtual = atual.first;
            int u = atual.second;
            fila.pop();

            if (distAtual > dist[u])
                continue;

            for (auto aresta : grafo[u]) {

                int v = aresta.first;
                int peso = aresta.second;

                if (dist[u] + peso < dist[v]) {

                    dist[v] = dist[u] + peso;

                    pai[v] = u;// Guarda de qual vértice viemos para alcançar 'v'

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

            vector<int> pai;

            auto dist = dijkstra(
                impares[i],
                g.getListaAdjacencia(),
                pai
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

    // 2.4 Duplicação de arestas
    vector<int> reconstruirCaminho(
        int origem,
        int destino,
        const vector<int>& pai
    ) {
        vector<int> caminho;

        int atual = destino;

        while (atual != -1) {
          caminho.push_back(atual);
           atual = pai[atual];
        }

        reverse(caminho.begin(), caminho.end());

        return caminho;
    }

    int obterPesoAresta(
        const Grafo& g,
        int u,
        int v
    ){
    for (auto aresta : g.getListaAdjacencia()[u]) {

        int vizinho = aresta.first;
        int peso = aresta.second;

          if (vizinho == v)
              return peso;
        }

        return -1;
    }

    void duplicarArestas(
        Grafo& g,
        const vector<int>& caminho
    ) {
        // Percorre cada aresta pertencente ao caminho mínimo.
        for (int i = 0; i < caminho.size() - 1; i++) {

            int u = caminho[i];
            int v = caminho[i + 1];

            int peso = obterPesoAresta(g, u, v);

            g.adicionarAresta(u, v, peso);
        }
    }


    // 2.5: Encontrar o circuito euleriano - Implementação do Algoritmo de Heilzor
    void removerAresta(
        vector<vector<pair<int,int>>>& lista,
        int u,
        int v
    ) {

        // Remove (v, peso) da lista de u
        for (auto it = lista[u].begin(); it != lista[u].end(); ++it) {

            if (it->first == v) {
                lista[u].erase(it);
                break;
            }
        }

        // Remove (u, peso) da lista de v
        for (auto it = lista[v].begin(); it != lista[v].end(); ++it) {

            if (it->first == u) {
                lista[v].erase(it);
                break;
            }
        }
    }

    
    vector<int> circuitoEuleriano(
        const Grafo& g,
        int inicio
    ) {

        // cópia da lista de adjacência
        auto lista = g.getListaAdjacencia();

        stack<int> pilha;
        vector<int> circuito;

        pilha.push(inicio);

        while (!pilha.empty()) {

            int u = pilha.top();

            if (!lista[u].empty()) {

                int v = lista[u].back().first;

                removerAresta(lista, u, v);

                pilha.push(v);
            }

            else {

                circuito.push_back(u);

                pilha.pop();
            }
        }

        reverse(circuito.begin(), circuito.end());

        return circuito;
    }

}