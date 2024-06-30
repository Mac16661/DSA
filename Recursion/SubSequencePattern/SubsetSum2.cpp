#include<bits/stdc++.h>
using namespace std;

// Finding sum of unique subset using unordered set
void Brute(int ind, vector<int> arr, unordered_set<int> &st, int sum) {
    
    if(ind == arr.size()) {
        st.insert(sum);
        // cout<<sum;
        return;
    }

    Brute(ind+1, arr, st, sum+arr[ind]);

    Brute(ind+1, arr, st, sum);
}

void Optimal(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){

    ans.push_back(ds);
        

    for(int i=ind; i<arr.size(); i++) {
        if(i != ind && arr[i] == arr[i-1]) continue;

        ds.push_back(arr[i]);
        Optimal(i+1, arr, ds, ans);
        ds.pop_back();
    }

}

void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }
      

void printAns(vector < vector < int >> & ans) {
   cout<<"The unique subsets are "<<endl;
   cout << "[ ";
   for (int i = 0; i < ans.size(); i++) {
      cout << "[ ";
      for (int j = 0; j < ans[i].size(); j++)
         cout << ans[i][j] << " ";
      cout << "]";
   }
   cout << " ]";
}

int main() {
    vector<int> arr{1,2,2,2,3,3};
    vector<int> ds;
    vector<vector<int>> ans;
    // unordered_set<int> st;

    // Brute(0, arr, st, 0);

    // for(auto i: st) cout<<i<<" ";
    // cout<<endl;

    Optimal(0, arr, ds, ans);
    // findSubsets(0,arr, ds, ans);
    printAns(ans);

    return 0;
}