#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Speed up I/O for large inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();
    vector<int> dp(n + 1, 0);

    // Precompute prefix sums of adjacent matches
    for (int i = 1; i < n; i++) {
        dp[i + 1] = dp[i] + (s[i] == s[i - 1] ? 1 : 0);
    }

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // The query asks for i such that l <= i < r and s[i] == s[i+1]
        // In our 1-based dp array, this maps to dp[r] - dp[l]
        cout << dp[r] - dp[l] << "\n";
    }

    return 0;
}