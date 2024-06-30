#include<bits/stdc++.h>
using namespace std;

void Optimal(int ind, vector<int> arr, vector<int> ds, int s) {

    if(ind == arr.size()) {
        
        cout<<s<<"->  ";
        int sum = 0;
        for(int i:ds) cout<<i<<" ";

        cout<<endl;
        
        return;
    }

    ds.push_back(arr[ind]);
    s+= arr[ind];
    Optimal(ind+1, arr, ds, s);

    ds.pop_back();
    s-= arr[ind];
    Optimal(ind+1, arr, ds, s);
}

int main() {
    vector<int> arr{4,1,2,3};
    vector<int> ds;

    Optimal(0, arr, ds, 0);
    return 0;
}