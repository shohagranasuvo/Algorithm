#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int parent[100];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) parent[i] = i;

    int totalCost = 0;
    cout << "Edges in MST:\n";
    for (Edge e : edges) {
        int a = find(e.u);
        int b = find(e.v);
        if (a != b) {
            totalCost += e.weight;
            parent[a] = b;
            cout << e.u << " - " << e.v << " : " << e.weight << endl;
        }
    }
    cout << "Total Cost: " << totalCost << endl;
}

int main() {
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 6}, {1, 2, 1}, {1, 3, 7}, {2, 3, 5}
    };
    int n = 4; // Number of vertices
    kruskal(edges, n);
    return 0;
}
