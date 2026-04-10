#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin>> n;

    int cnt = 0;
    int p, q;

    for (int i = 0; i < n; i++) {
        cin >> p >> q;

        if (q - p > 1)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}