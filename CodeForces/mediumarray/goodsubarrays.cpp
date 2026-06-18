#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Hash map to store frequencies of transformed prefix sums
    unordered_map<int, int> prefix_counts;
    
    // Base case: a prefix sum of 0 has appeared 1 time initially
    prefix_counts[0] = 1;
    
    long long good_subarrays = 0;
    int current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        // Transform the element by subtracting 1: (a_i - 1)
        int val = (s[i] - '0') - 1;
        current_sum += val;
        
        // If this prefix sum has been seen before, it forms valid subarrays
        if (prefix_counts.count(current_sum)) {
            good_subarrays += prefix_counts[current_sum];
        }
        
        // Increment the count of the current prefix sum
        prefix_counts[current_sum]++;
    }
    
    cout << good_subarrays << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
