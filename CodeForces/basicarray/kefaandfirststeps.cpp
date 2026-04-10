#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0; i < n; i++) {
        cin>> arr[i];
    }
    
    int maxCnt = 1;
    int currentCnt = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) {
            currentCnt++;
        } else {
            maxCnt = max(maxCnt, currentCnt);
            currentCnt = 1;
        }
    }

    cout << max(maxCnt, currentCnt) << endl;
    return 0;
}