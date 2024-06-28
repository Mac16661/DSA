#include<bits/stdc++.h>
using namespace std;

int CountSubseq(vector<int> arr, vector<int> ds, int idx, int sum, int s) {

    if(s>sum) return 0;

    if(idx == arr.size()) {
        if(s == sum) {
            for(auto i:ds) cout<<i<<" ";
            cout<<endl;
            return 1;
        }
        return 0;
    }


    ds.push_back(arr[idx]);
    s+= arr[idx];
    int left = CountSubseq(arr, ds, idx+1, sum, s);

    ds.pop_back();
    s-= arr[idx];
    int right = CountSubseq(arr, ds, idx+1, sum, s);

    return left+right;
}

int main() {
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    vector<int> ds;

    cout<<CountSubseq(arr, ds, 0, 10, 0)<<endl;
    return 0;
}