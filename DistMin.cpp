#include <bits/stdc++.h>
#include <cctype>
using namespace std;

#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define int long long
#define endl '\n'

signed main() {
    op

    int n = 4;
    vector<vector<int>> grafo(n);
    grafo[0].push_back(1);
    grafo[0].push_back(2);

    grafo[1].push_back(0);
    grafo[1].push_back(2);
    grafo[1].push_back(3);

    grafo[2].push_back(0);
    grafo[2].push_back(3);

    grafo[3].push_back(1);
    grafo[3].push_back(2);

    for(int i = 0; i < n; i++) {

        cout << i << ": ";

        for(int vizinho : grafo[i]) {
            cout << vizinho << " ";
        }

        cout << endl;
    }
}