#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

void topSortUtil(int u, int V) {
    visited[u] = true;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v])
            topSortUtil(v, V);
    }
    push(u);
}

void topologicalSort(int V) {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topSortUtil(i, V);

    while (top != -1)
        cout << pop() << " ";
}

int main() {
    int V = 6;

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V);

    return 0;
}
