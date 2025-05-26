#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, vector<bool>& visited, vector<int> adj[]) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v])
            dfsUtil(v, visited, adj);
    }
}

void dfs(int V, vector<int> adj[], int start) {
    vector<bool> visited(V, false);
    dfsUtil(start, visited, adj);
}
