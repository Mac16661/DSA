#include<bits/stdc++.h>
using namespace std;

// TODO: All posible subsequence with sum k (check CheckSubsequenceWithSumKExixts for more optimized soln)
void SubseqSum(vector<int> arr, vector<int> ds,int sum, int idx) {

    if(idx == arr.size()) {
        int cnt = 0;
        for(auto i : ds) {
            cnt+= i;
        }

        if(cnt == sum) {
            for(auto i : ds) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[idx]);
    SubseqSum(arr, ds, sum, idx+1);

    ds.pop_back();
    SubseqSum(arr, ds, sum, idx+1);
}

int main() {
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    vector<int> ds;

    SubseqSum(arr, ds,10, 0);
    return 0;
}