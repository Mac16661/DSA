#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        int inp;
        cin>> inp;
        arr[i] = inp;
    }

    vector<int> ans(n);
    for (int i=0; i < n; i++) {
        ans[arr[i]-1] = i + 1;
    }

    for (int x: ans) {
        cout << x << endl;
    }

    return 0;
}