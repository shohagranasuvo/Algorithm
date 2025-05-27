#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topSortUtil(int u, vector<bool>& visited, stack<int>& st, vector<int> adj[]) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            topSortUtil(v, visited, st, adj);
    }
    st.push(u);
}

void topologicalSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topSortUtil(i, visited, st, adj);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
int main() {
    int V = 6; 

    
    vector<int> adj[V];

    
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort of the given graph:\n";
    topologicalSort(V, adj);

    return 0;
}

