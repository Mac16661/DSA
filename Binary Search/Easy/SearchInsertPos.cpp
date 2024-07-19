#include<bits/stdc++.h>
using namespace std;

// TODO: Same as lower bound
int searchInsert(vector<int> arr, int x, int low, int high) {
    static int ans = arr.size();
    if(low > high) return ans;

    int mid = (low+high) / 2;

    if(arr[mid] >= x) {
        ans=mid;
        return searchInsert(arr, x, low, mid-1);
    }else{
        return searchInsert(arr, x, mid+1, high);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x,0,arr.size()-1);
    cout << "The index is: " << ind << "\n";
    return 0;
}