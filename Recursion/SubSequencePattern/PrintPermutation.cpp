#include<bits/stdc++.h>
using namespace std;

// Brute force approach
void recurPermute(vector<int> &arr, vector<int> &ds, vector<int> &freq, vector<vector<int>> &ans ) {

    if(ds.size() == arr.size()) {
        ans.push_back(ds);
        return;
    }

    for(int i=0; i<arr.size(); i++) {
        if(!freq[i]) {
            ds.push_back(arr[i]);
            freq[i] = 1;
            recurPermute(arr, ds, freq, ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

// Optimal for permutation
void recurPermuteOptim(int ind, vector<int> arr) {
    if(ind == arr.size()) {
        for(auto i : arr) cout<<i<<" ";
        cout<<endl;
    }

    for(int i = ind; i<arr.size(); i++) {
        swap(arr[ind], arr[i]);
        recurPermuteOptim(ind+1, arr);
        swap(arr[ind], arr[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);

    recurPermute(nums, ds, freq, ans);
    recurPermuteOptim(0, nums);

    return ans;
}

int main() {
    vector<int> arr{1,2,3};
    
    vector<vector<int>> ans = permute(arr);

    cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

    
    return 0;
}