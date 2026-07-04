#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void gerar_grafo_aleatorio(int n, int m) {
    for (int i = 1; i < n; i++) adicionar_aresta(i, i + 1, rand() % 10 + 1);
    for (int i = 0; i < m - (n - 1); i++) {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        if (u != v) adicionar_aresta(u, v, rand() % 10 + 1);
    }
}

