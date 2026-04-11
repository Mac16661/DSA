#include <bits/stdc++.h>

using namespace std;

int main () {
    int k, n, w;
    cin >> k >> n >> w;
    
    long long price = 0;
    for (int i=1; i <=w; i++) {
        price += (k * i);
    }

    cout << max(0LL, price - n) << endl;
    return 0;
}