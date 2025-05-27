#include <iostream>
using namespace std;

#define MAX 100

void dfsUtil(int u, bool visited[], int adj[][MAX], int V) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v])
            dfsUtil(v, visited, adj, V);
    }
}

void dfs(int V, int adj[][MAX], int start) {
    bool visited[MAX] = {false};
    dfsUtil(start, visited, adj, V);
}

int main() {
    int V = 6;
    int adj[MAX][MAX] = {0};

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][0] = 1;
    adj[1][3] = 1;
    adj[2][0] = 1;
    adj[2][4] = 1;
    adj[3][1] = 1;
    adj[4][2] = 1;
    adj[4][5] = 1;
    adj[5][4] = 1;

    int startNode = 0;
    dfs(V, adj, startNode);

    return 0;
}
