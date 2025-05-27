#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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
    cout << "BFS traversal starting from node " << startNode << ":\n";
    bfs(startNode, V, adj);

    return 0;
}
