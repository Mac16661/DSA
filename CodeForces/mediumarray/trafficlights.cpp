#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    char l;
    cin >> n >> l;
    string s;
    cin >> s;

    // If we are already at green, the maximum wait time is 0
    if (l == 'g') {
        cout << 0 << "\n";
        return;
    }

    // Duplicate string to effortlessly handle circular wrapping
    s += s; 
    
    int max_dist = 0;
    int last_green_pos = -1;

    // Scan backward from the end of the duplicated string
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (s[i] == 'g') {
            last_green_pos = i;
        }
        
        // If we find our target letter and we have seen a green light ahead
        if (s[i] == l && last_green_pos != -1) {
            // We only care about starting positions within the original string length
            if (i < n) {
                max_dist = max(max_dist, last_green_pos - i);
            }
        }
    }

    cout << max_dist << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
