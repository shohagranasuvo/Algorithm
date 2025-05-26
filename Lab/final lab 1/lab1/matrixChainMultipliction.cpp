#include <iostream>
#include <climits>
using namespace std;
int matrixChain(int p[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                m[i][j] = min(m[i][j], cost);
            }
        }
    }
    return m[1][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n+1];
    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    cout << "Minimum number of multiplications: " << matrixChain(p, n+1) << endl;
    return 0;
}
