#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    vector<long long> b(n);
    long long min_val = 2e9 + 7; // Initialize with extreme values
    long long max_val = -1;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] < min_val) min_val = b[i];
        if (b[i] > max_val) max_val = b[i];
    }

    long long min_cnt = 0;
    long long max_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] == min_val) min_cnt++;
        if (b[i] == max_val) max_cnt++;
    }

    long long diff = max_val - min_val;
    long long num_ways = 0;

    // Fix: Handle the case where all elements are identical
    if (min_val == max_val) {
        num_ways = n * (n - 1) / 2;
    } else {
        num_ways = min_cnt * max_cnt;
    }

    cout << diff << " " << num_ways << "\n";

    return 0;
}
