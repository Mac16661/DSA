#include <bits/stdc++.h>

using namespace std;

int upperbound(vector<int>& prices, int q) {
    int n = prices.size();

    if (q >= prices[n-1])
        return n;
    
    int l = 0, r = n-1;
    int ans = 0;

    while (l <= r) {
        int mid = (l+r) / 2;

        if (prices[mid] > q) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int main () {
    int n, q;
    cin >> n;

    vector<int> price(n);
    for (int i=0; i < n; i++) {
        cin>> price[i];
    }

    cin >> q;
    vector<int> coins(q);
    for (int i=0; i < q; i++) {
        cin>> coins[i];
    }
    
    sort(price.begin(), price.end());

    // Use binary search on answers4
    for (int i = 0; i < q; i++) {
        cout << upperbound(price, coins[i]) << endl;
    }

    return 0;
}