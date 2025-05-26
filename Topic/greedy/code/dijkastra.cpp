#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

void dijkstra(int V, int start, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > currentDist + weight) {
                dist[v] = currentDist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "Distance to " << i << ": " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 7});
    adj[3].push_back({2, 6});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    int start = 0;
    dijkstra(V, start, adj);

    return 0;
}
