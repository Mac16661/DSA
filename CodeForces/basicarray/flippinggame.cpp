#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxOnes = 0;

    // 1. Try every possible starting point 'i'
    for (int i = 0; i < n; i++) {
        // 2. Try every possible ending point 'j'
        for (int j = i; j < n; j++) {
            
            // 3. Count 1s after flipping the range [i, j]
            int currentOnes = 0;
            for (int k = 0; k < n; k++) {
                int val = a[k];
                // If k is within the flip range [i, j], flip the bit
                if (k >= i && k <= j) {
                    val = 1 - val; // 0 becomes 1, 1 becomes 0
                }
                if (val == 1) {
                    currentOnes++;
                }
            }
            
            // Update the maximum found so far
            maxOnes = max(maxOnes, currentOnes);
        }
    }

    cout << maxOnes << endl;
    return 0;
}
