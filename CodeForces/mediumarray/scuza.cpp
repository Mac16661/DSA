#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    vector<long long> pref_sum(n + 1, 0);
    vector<long long> pref_max(n + 1, 0);
    
    long long current_max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref_sum[i + 1] = pref_sum[i] + a[i];
        current_max = max(current_max, a[i]);
        pref_max[i + 1] = current_max;
    }
    
    for (int i = 0; i < q; i++) {
        long long k;
        cin >> k;
        
        // upper_bound finds the first element > k
        auto it = upper_bound(pref_max.begin(), pref_max.end(), k);
        // Step back by 1 to get the largest element <= k
        int j = distance(pref_max.begin(), it) - 1;
        
        cout << pref_sum[j] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
