#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(b.begin(), b.end());

    long long min_val = b[0];
    long long max_val = b[n - 1];
    long long diff = max_val - min_val;

    if (diff == 0) {
        // All flowers are the same, use nCr: n(n-1)/2
        cout << 0 << " " << n * (n - 1) / 2 << endl;
    } else {
        long long cnt_min = 0, cnt_max = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == min_val) cnt_min++;
            if (b[i] == max_val) cnt_max++;
        }
        // Multiply frequencies for distinct min/max
        cout << diff << " " << cnt_min * cnt_max << endl;
    }

    return 0;
}
