#include <bits/stdc++.h>

using namespace std;

// lower bound binary search: print idx+1 , l - pref[idx-1]
void solve(const vector<long long>& pref, long long l) {
    int low = 0, high = pref.size() - 1;
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (pref[mid] >= l) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Math for room calculation:
    // If it's the 0th dorm, local room is just 'l'.
    // Otherwise, subtract the total rooms of all previous dorms (pref[ans-1]).
    long long local_room = (ans == 0) ? l : l - pref[ans - 1];

    cout << ans + 1 << " " << local_room << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0)
            continue;

        arr[i] = arr[i] + arr[i-1]; // prefix
    }
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    for (int i = 0 ; i < m; i++) {
        long long l;
        cin>>l;
        solve(arr, l);
    }

    return 0;
}