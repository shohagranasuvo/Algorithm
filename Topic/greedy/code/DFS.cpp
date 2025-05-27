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
int main() {
    int V = 6; 

   
    vector<int> adj[V];

    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);

    int startNode = 0;
    cout << "DFS traversal starting from node " << startNode << ":\n";
    dfs(V, adj, startNode);

    return 0;
}
