#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, k;
    cin>> n >> k;

    while(k) {
        int rem = n % 10;

        if (rem != 0)
            n--;
        else
            n = n / 10;

        k--;
    }

    cout << n << endl;
    return 0;
}