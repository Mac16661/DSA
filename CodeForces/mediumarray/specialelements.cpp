#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0 ; i  < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int t = 0; t < n; t++) {
        int target = arr[t];
        int sum = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            while (sum > target && j <= i) {
                sum -= arr[j];
                j++;
            }

            if (sum == target && (i - j + 1) >= 2) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
