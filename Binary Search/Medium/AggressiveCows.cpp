#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr[arr.size()-1] - arr[0];

    while(low <= high) {
        int mid = (low+high) / 2;

        if(canWePlace(arr, mid, k)){
            low = mid+1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}