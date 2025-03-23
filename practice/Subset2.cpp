#include<bits/stdc++.h>
using namespace std;

void subSet(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int idx) {
    ans.push_back(ds);

    // No need any external retune bec loop will run till arr size and return executio to the caller function
    for(int i=idx; i<arr.size(); i++) {
        if(i != idx && arr[i] == arr[i-1]) continue; // if first iteration then push(no need to check prev elelment)

        ds.push_back(arr[i]);
        subSet(arr, ds, ans, i+1);  // for next call we are strting after the ith iteration 
        ds.pop_back();
    }
}

int main() {
    vector<int> arr = {1,2,2};
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    subSet(arr, ds, ans, 0);

    for(auto i:ans) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}