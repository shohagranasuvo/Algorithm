#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void bfs(int start, int V, int adj[][MAX]) {
    bool visited[MAX] = {false};

    visited[start] = true;
    enqueue(start);

    while (!isEmpty()) {
        int u = dequeue();
        cout << u << " ";

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                enqueue(v);
            }
        }
    }
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
    bfs(startNode, V, adj);

    return 0;
}
