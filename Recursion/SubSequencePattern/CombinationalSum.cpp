#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> arr, vector<int> &ds, vector<vector<int>> &ret, int sum, int idx) {

    if(idx == arr.size()) {
        if(sum == 0) {
            ret.push_back(ds);
            // ds.clear();
        }
        return;
    }

    if(arr[idx] <= sum) {
        ds.push_back(arr[idx]);
        helper(arr, ds, ret, sum-arr[idx], idx);
        ds.pop_back();
    }

    helper(arr, ds, ret, sum, idx+1);

}

vector<vector<int>> CombinationalSum(){
    vector<int> arr = {2,3,6,7};
    vector<int> ds;
    int target = 7;

    vector<vector<int>> ret;

    helper(arr, ds, ret,  target, 0);

    return ret;
}

int main() {
    cout<<"[ ";
    for(auto i : CombinationalSum()) {
        cout<<"[ ";
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<" ] ";
    }
    cout<<" ]"<<endl;
    return 0;
}