#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    int cnt = 0;
    while(n) {
        if (n >= 100)
            n -= 100;
        else if (n >= 20)
            n -= 20;
        else if (n >= 10)
            n -= 10;
        else if (n >= 5)
            n -= 5;
        else
            n -= 1;

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}