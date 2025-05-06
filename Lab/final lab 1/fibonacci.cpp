#include <iostream>
using namespace std;

int fibonacci(int n) {
    int f[n+2];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];

    return f[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    return 0;
}
