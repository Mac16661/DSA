#include<bits/stdc++.h>
using namespace std;

void Sum(vector<int> arr, int t, int ind, int sum, int &counter) {
    if(ind >= arr.size()){
        if(sum == t) {
            counter++;
        }
        return;
    }

    Sum(arr, t, ind+1, sum, counter);

    sum+= arr[ind];

    Sum(arr, t, ind+1, sum, counter);
}

bool SumBool(vector<int> arr, int t, int ind, int sum) {
    if(ind >= arr.size()){
        if(sum == t) {
            return true;
        }
        return false;
    }

    if (SumBool(arr, t, ind+1, sum)){
        return true;
    }

    sum+= arr[ind];

    if(SumBool(arr, t, ind+1, sum)){
        return true;
    }

    return false;
}

int main() {
    vector<int> arr = {4, 2, 5, 6, 7};
    // int counter = 0;
    // Sum(arr, 10, 0, 0, counter);
    // cout<<counter<<endl;

    cout<<SumBool(arr, 14, 0, 0)<<endl;
    return 0;
}