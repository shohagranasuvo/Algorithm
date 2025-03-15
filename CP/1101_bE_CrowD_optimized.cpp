#include <iostream>
using namespace std;

int calculateRangeSum(int start, int end) {
    // Using arithmetic sequence formula: sum = n(a1 + an)/2
    // where n is number of terms, a1 is first term, an is last term
    long long n = end - start + 1;
    return (n * (start + end)) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);  // Optimization for cin/cout
    cin.tie(nullptr);
    
    while (true) {
        int a, b;
        cin >> a >> b;
        
        // Check for termination condition
        if (a <= 0 || b <= 0) {
            break;
        }
        
        // Find min and max without using function calls
        int start = (a < b) ? a : b;
        int end = (a > b) ? a : b;
        
        // Print the sequence
        for (int i = start; i <= end; i++) {
            cout << i << " ";
        }
        
        // Calculate and print sum
        cout << "Sum=" << calculateRangeSum(start, end) << endl;
    }
    
    return 0;
} 