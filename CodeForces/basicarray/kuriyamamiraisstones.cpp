#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0 ; i < n; i++) {
        cin>> arr[i];
    }

    vector<long long> pref(n), sortPref(n);
    pref[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    sort(arr.begin(), arr.end());
    sortPref[0] = arr[0];
    for (int i = 1 ; i < n; i++) {
        sortPref[i] = sortPref[i-1] + arr[i];
    }

    int m;
    cin>> m;
    int t, l, r;
    while (m--) {
        cin>> t >> l >> r;

        l--; // 1 based indexing
        r--; // 1 based indexing
        long long ans;
        if (t == 1) {
            ans = (l != 0 ? pref[r] - pref[l - 1] : pref[r]);
        }else {
            ans = (l != 0 ? sortPref[r] - sortPref[l - 1] : sortPref[r]);
        }

        cout << ans << endl;
    }

    return 0;
}
