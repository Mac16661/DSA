#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin>> n;

    if (n < 2){
        cout<< n <<endl;
        return 0;
    }

    int cnt = 1;
    int last = -1;
    int m;

    for (int i = 0; i < n; i++) {
        cin >> m;

        if (last != -1 && m != last)
            cnt++;

        last = m;
    }

    cout << cnt << endl;
    return 0;
}