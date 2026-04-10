#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, t;
    cin>> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Brute force approach
    // for (int i = 0; i < n; i++) {
    //     int temp = t;
    //     for (int j = i; j < n; j++) {
    //         if (temp < arr[j]) {
    //             break;
    //         }
    //         int len = j - i + 1;
    //         maxLen = max(len, maxLen);
    //         // cout << j << " - " << i << " + 1, maxLen:: "<<maxLen << endl;
    //         if (j == n-1) {
    //             cout<< maxLen <<endl;
    //             return 0;
    //         }
    //         temp -= arr[j];
    //     }
    // }

    // Optimized two pointer
    int i = 0; 
    int maxLen = 0;

    for (int j = 0; j < n; j++) {
        while (i <= j && arr[j] > t) {
            t += arr[i];
            i++;
        }

        if (arr[j] <= t) {
            maxLen = max(maxLen, j - i + 1);
            t -= arr[j];
        } else {
            i++;
            j++;
        }
    }

    cout << maxLen << endl;

    return 0;
}