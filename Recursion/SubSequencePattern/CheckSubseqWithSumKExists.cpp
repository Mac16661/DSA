// TODO: VERY IMP -> Printing only one answer
#include<bits/stdc++.h>
using namespace std;

bool SingleSubseqWithSumK(vector<int> arr, vector<int> ds, int idx, int sum, int s) {

    if(idx == arr.size()) {
        if(s==sum) {
            for(auto i: ds) {
                cout<<i<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[idx]);
    s+= arr[idx];
    if(SingleSubseqWithSumK(arr, ds, idx+1, sum, s)) {
        return true;
    } 

    s-= arr[idx];
    ds.pop_back();
    if(SingleSubseqWithSumK(arr, ds, idx+1, sum, s)) {
        return true;
    }
    
    return false;

}

int main() {
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    vector<int> ds;

    SingleSubseqWithSumK(arr, ds, 0, 10, 0);
    return 0;
}