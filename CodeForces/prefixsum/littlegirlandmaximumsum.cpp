#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Num elements
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        pq.push(ele);
    }

    // TODO: Not efficient, need to fix with difference array
    // vector<int> arr;
    // for (int i = 0; i < q; i++) {
    //     int l, r;
    //     cin >> l >> r;

    //     if (arr.size() <= r) {
    //         arr.resize(r + 1, 0); 
    //     }

    //     // 2. Now safely increment the range
    //     for (int j = l; j <= r; j++) {
    //         arr[j]++;
    //     }
    // }

    // Optimal way of updating ranges using difference array (prefix sum method)
    vector<int> diff(n + 1, 0);
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        diff[l] += 1;
        if (r + 1 <= n)
            diff[r + 1] -= 1;
    }

    // Now calculate prefix sum using the difference array
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i-1];
    }

    // Usually in difference array algo we now add arr[i] += diff[i]
    // but for our case it wont make a difference. Because we are
    // just incrementing it by 1

    sort(diff.begin() + 1, diff.begin() + n + 1); // To accommodate n + 1 (or one based indexing)
    long long sum = 0;
    for (int i = n; i >= 1; i--) {
        if (pq.empty())
            break;

        int x = pq.top();
        pq.pop();

        sum += 1LL * x * diff[i];
    }
    
    cout << sum <<endl;

    return 0;
}