#include<bits/stdc++.h>
using namespace std;

string twoSumBetter(int n, vector<int> arr, int target) {
    unordered_map<int,int> mp;

    for(int i=0; i<n; i++) {
        mp[arr[i]] = i;
    }


    for(int i=0; i<n; i++) {
        int temp = target - arr[i];
        auto it = mp.find(temp);
        if(it != mp.end()){
            return "yes";
        }
    }

    return "no";
}

// TODO: Greedy approach (optimal)
string twoSum(int n, vector<int> arr, int target) {
    int i=0;
    int j = n-1;

    while(i < j) {
        if(arr[i] + arr[j] > target) j--;   // if i+j is overshoot then we decrease j(as j is the biggest)
        else if(arr[i] + arr[j] < target) i++;  // if the sum is smaller then target then we will increment i as it might make upto the sum
        else return "yes";
    }

    return "no";
}

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}